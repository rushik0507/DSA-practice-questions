package com.example.client;

import com.google.gwt.core.client.JavaScriptObject;
import com.google.gwt.user.client.Window;
import com.google.gwt.user.client.rpc.AsyncCallback;

public class EncryptionUtils {

    public static void encryptText(String text, String publicMod, String publicExp, AsyncCallback<String> callback) {
        importKey(publicMod, publicExp, new AsyncCallback<JavaScriptObject>() {
            @Override
            public void onSuccess(JavaScriptObject key) {
                encrypt(text, key, callback);
            }

            @Override
            public void onFailure(Throwable caught) {
                Window.alert("Error importing public key: " + caught.getMessage());
                callback.onFailure(caught);
            }
        });
    }

    private static void encrypt(String text, JavaScriptObject key, AsyncCallback<String> callback) {
        try {
            encryptNative(text, key, callback);
        } catch (Exception e) {
            Window.alert("Error encrypting text: " + e.getMessage());
            callback.onFailure(e);
        }
    }

    private static void importKey(String publicMod, String publicExp, AsyncCallback<JavaScriptObject> callback) {
        try {
            importKeyNative(publicMod, publicExp, callback);
        } catch (Exception e) {
            Window.alert("Error importing key: " + e.getMessage());
            callback.onFailure(e);
        }
    }

    private static native void importKeyNative(String publicMod, String publicExp, AsyncCallback<JavaScriptObject> callback) /*-{
        const alg = { name: "RSA-OAEP", hash: "SHA-256" };
        const jwk = { kty: "RSA", n: publicMod, e: publicExp };
        
        $wnd.crypto.subtle.importKey("jwk", jwk, alg, false, ["encrypt"])
            .then(function(key) {
                callback.@com.google.gwt.user.client.rpc.AsyncCallback::onSuccess(*)(key);
            })
            .catch(function(error) {
                callback.@com.google.gwt.user.client.rpc.AsyncCallback::onFailure(*)(error);
            });
    }-*/;

    private static native void encryptNative(String text, JavaScriptObject key, AsyncCallback<String> callback) /*-{
        const textEncoder = new TextEncoder();
        const encodedText = textEncoder.encode(text);

        $wnd.crypto.subtle.encrypt({ name: "RSA-OAEP" }, key, encodedText)
            .then(function(cipherText) {
                const base64Text = btoa(String.fromCharCode(...new Uint8Array(cipherText)));
                callback.@com.google.gwt.user.client.rpc.AsyncCallback::onSuccess(*)(base64Text);
            })
            .catch(function(error) {
                callback.@com.google.gwt.user.client.rpc.AsyncCallback::onFailure(*)(error);
            });
    }-*/;

    // Utility function to convert Hex to Uint8Array
    public static Uint8Array convertHexToUint8Array(String hexString) {
        if (hexString.length() % 2 != 0) {
            hexString = "0" + hexString;
        }
        int length = hexString.length() / 2;
        Uint8Array array = new Uint8Array(length);
        for (int i = 0; i < length; i++) {
            array.set(i, Integer.parseInt(hexString.substring(i * 2, i * 2 + 2), 16));
        }
        return array;
    }
}