package com.example.client;

import com.google.gwt.core.client.JavaScriptObject;
import jsinterop.annotations.JsMethod;
import jsinterop.annotations.JsType;
import jsinterop.base.Js;

public class EncryptionUtils {

    // Encrypts the text using the provided public modulus and exponent
    public static void encryptText(String text, String publicMod, String publicExp, EncryptionCallback callback) {
        try {
            JsonWebKey jwk = JsonWebKey.create();
            jwk.kty = "RSA";
            jwk.n = base64UrlSafeEncode(convertHexToUint8Array(publicMod));
            jwk.e = base64UrlSafeEncode(convertHexToUint8Array(publicExp));

            CryptoKey key = importKey(jwk);

            // Encoding the text and encrypting
            Uint8Array encodedText = new Uint8Array(text);
            window.crypto.subtle.encrypt("RSA-OAEP", key, encodedText).then(cipherText -> {
                String cipherStrBase64 = base64UrlSafeEncode(cipherText);
                callback.onSuccess(cipherStrBase64);
            }).catchError(error -> {
                callback.onError("ERROR encrypting text: " + error.toString());
            });
        } catch (Exception e) {
            callback.onError("Encryption failed: " + e.getMessage());
        }
    }

    // Converts a hex string to Uint8Array
    public static Uint8Array convertHexToUint8Array(String hexString) {
        // Add padding if needed
        if (hexString.length() % 2 != 0) {
            hexString = "0" + hexString;
        }
        
        byte[] bytes = new byte[hexString.length() / 2];
        for (int i = 0; i < hexString.length(); i += 2) {
            bytes[i / 2] = (byte) Integer.parseInt(hexString.substring(i, i + 2), 16);
        }
        
        return new Uint8Array(bytes);
    }

    // Base64 URL Safe Encoding
    public static native String base64UrlSafeEncode(Uint8Array buffer) /*-{
        let binary = '';
        let bytes = new Uint8Array(buffer);
        let len = bytes.byteLength;
        for (let i = 0; i < len; i++) {
            binary += String.fromCharCode(bytes[i]);
        }
        return btoa(binary).replace(/\+/g, '-').replace(/\//g, '_').replace(/=+$/, '');
    }-*/;

    // Import a JWK key for encryption
    public static native CryptoKey importKey(JsonWebKey jwk) /*-{
        return $wnd.crypto.subtle.importKey(
            "jwk",
            jwk,
            { name: "RSA-OAEP", hash: "SHA-256" },
            false,
            ["encrypt"]
        );
    }-*/;

    // Callback interface for encryption result handling
    public interface EncryptionCallback {
        void onSuccess(String cipherText);
        void onError(String error);
    }
    
    // Define JavaScript types
    @JsType(isNative = true, namespace = "window", name = "Uint8Array")
    public static class Uint8Array extends JavaScriptObject {
        protected Uint8Array() {}
        public Uint8Array(String str) { }
    }

    @JsType(isNative = true, namespace = "window.crypto.subtle", name = "CryptoKey")
    public static class CryptoKey extends JavaScriptObject {
        protected CryptoKey() {}
    }

    @JsType(isNative = true)
    public static class JsonWebKey extends JavaScriptObject {
        public String kty;
        public String n;
        public String e;

        public static native JsonWebKey create() /*-{
            return {};
        }-*/;
    }
}