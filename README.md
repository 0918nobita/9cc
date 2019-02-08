# 9cc

## 開発環境について

Docker を用いて構築した Arch linux の仮想環境で開発しています。

### Docker イメージの作成

```bash
docker build -t 9cc .
```

### Docker コンテナの起動

```bash
docker run -i -t 9cc /bin/bash
```

Control + P, Q でコンテナを起動したまま bash から抜けられます。  
起動中のコンテナに再度ログインするには ``docker attach <コンテナID>`` を実行します。

### Docker コンテナの停止

```
docker stop <コンテナID>
```
