com\_port\_opner
====
COMポートを強制解放するツール。<br>

想定される使用状況は、COMポートを使用するソフトウェアが異常終了した際、COMポートを解放できなかった場合である。<br>
そのソフトウェアが使用していたCOMポートは、以降使用ができなくなってしまう。<br>
これを解決するには、レジストリのCOMポート使用中フラグを書き換えればよい。<br>

```
HKEY\_LOCAL\_MACHINE
  SYSTEM
    CurrentControlSet
      Control
        COM Name Arbiter
```

参考URL:
「Windowsで増えすぎたCOMポートを解放する」(https://qiita.com/ZeroCrossroad/items/fadcc2a8cc33aaf18c26)
