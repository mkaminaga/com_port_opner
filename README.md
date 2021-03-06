﻿com\_port\_opner
====
COMポートを強制解放するツール。<br>

想定使用状況は、COMポートを使用するソフトウェアが異常終了した際、COMポートが解放されなかった場合である。<br>
そのソフトウェアが使用していたCOMポートは、以後使用できなくなってしまう。<br>
これを解決するには、下記レジストリキーのエントリ「ComDB」のバイナリを書き換える。<br>

```
HKEY_LOCAL_MACHINE
  SYSTEM
    CurrentControlSet
      Control
        COM Name Arbiter
```

ComDBの値はバイナリ形式である。<br>
LSBから順にCOM1、COM2、...という順に各COMポートの使用状況を示すビットが割り当てられている。<br>

このツールを使用すれば、以下のダイアログに解放したいCOMポートの番号を入力することで、このビットをクリアすることができる。
```
Which COM port to open? (1 - 128)
>
```

注意事項
----
 * 管理者権限で実行すること
 * レジストリを弄るので、動作を理解してから使用しないと事故につながる
 * COM1からCOM128までが有効

参考
----
[Windowsで増えすぎたCOMポートを解放する](https://qiita.com/ZeroCrossroad/items/fadcc2a8cc33aaf18c26)
