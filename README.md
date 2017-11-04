com\_port\_opner
====
COMポートを強制解放するツール。<br>

想定使用状況は、COMポートを使用するソフトウェアが異常終了した際、COMポートを解放できなかった場合である。<br>
そのソフトウェアが使用していたCOMポートは、以降使用ができなくなってしまう。<br>
これを解決するには、下記レジストリキーのComDBのバイナリを書き換える。<br>

```
HKEY_LOCAL_MACHINE
  SYSTEM
    CurrentControlSet
      Control
        COM Name Arbiter
```

手動でレジストリを弄るのがめんどくさいのでツール化した。

注意事項
----
 * 管理者権限で実行すること
 * レジストリを弄るので、動作を理解してから使用しないと事故につながる

参考
----
[Windowsで増えすぎたCOMポートを解放する](https://qiita.com/ZeroCrossroad/items/fadcc2a8cc33aaf18c26)
