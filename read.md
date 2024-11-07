public class CryptoUtil {

    // Import key from JWK
    public native void importKey(String jwk, ImportKeyCallback callback) /*-{
        var self = this;
        window.crypto.subtle.importKey(
            "jwk", // Format of the key
            JSON.parse(jwk), // Parse the JWK string to JSON
            {
                name: "AES-GCM"
            },
            true, // Whether the key is extractable (for reuse)
            ["encrypt", "decrypt"]
        ).then(function(key) {
            self.@com.example.client.CryptoUtil::encryptionKey = key;
            callback.@com.example.client.CryptoUtil.ImportKeyCallback::onSuccess()();
        }).catch(function(err) {
            callback.@com.example.client.CryptoUtil.ImportKeyCallback::onError(*)(err.toString());
        });
    }-*/;

    // Store the imported encryption key
    private Object encryptionKey;

    // Encrypt data
    public native void encryptData(String data, EncryptionCallback callback) /*-{
        var self = this;
        var iv = window.crypto.getRandomValues(new Uint8Array(12)); // Generate an IV
        
        window.crypto.subtle.encrypt(
            {
                name: "AES-GCM",
                iv: iv
            },
            self.@com.example.client.CryptoUtil::encryptionKey,
            new TextEncoder().encode(data)
        ).then(function(encrypted) {
            var encryptedData = new Uint8Array(encrypted);
            var result = new Uint8Array(iv.length + encryptedData.length);
            result.set(iv);
            result.set(encryptedData, iv.length);
            callback.@com.example.client.CryptoUtil.EncryptionCallback::onSuccess(*)(result);
        }).catch(function(err) {
            callback.@com.example.client.CryptoUtil.EncryptionCallback::onError(*)(err.toString());
        });
    }-*/;

    // Decrypt data
    public native void decryptData(Uint8Array encryptedData, DecryptionCallback callback) /*-{
        var self = this;
        var iv = encryptedData.slice(0, 12); // Extract the IV
        var data = encryptedData.slice(12); // Extract encrypted data

        window.crypto.subtle.decrypt(
            {
                name: "AES-GCM",
                iv: iv
            },
            self.@com.example.client.CryptoUtil::encryptionKey,
            data
        ).then(function(decrypted) {
            var decryptedText = new TextDecoder().decode(new Uint8Array(decrypted));
            callback.@com.example.client.CryptoUtil.DecryptionCallback::onSuccess(*)(decryptedText);
        }).catch(function(err) {
            callback.@com.example.client.CryptoUtil.DecryptionCallback::onError(*)(err.toString());
        });
    }-*/;

    // Callback interface for importing key
    public interface ImportKeyCallback {
        void onSuccess();
        void onError(String error);
    }

    // Callback interface for encryption
    public interface EncryptionCallback {
        void onSuccess(Uint8Array encryptedData);
        void onError(String error);
    }

    // Callback interface for decryption
    public interface DecryptionCallback {
        void onSuccess(String decryptedText);
        void onError(String error);
    }
}