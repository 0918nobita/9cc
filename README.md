# 9cc

## 開発環境について

Docker を用いて構築した Arch linux の仮想環境で開発しています。

### イメージの作成

```bash
docker-compose build
```

### コンテナの起動 + ログイン (初回)

```bash
docker-compose run dev /bin/bash
```

Control + P, Q でコンテナを起動したまま bash から抜けられます。

### 起動中のコンテナに再度ログインする

```bash
docker attach <コンテナID>
```

### コンテナの停止

```
docker stop <コンテナID>
```

### コンテナの削除

```bash
docker rm <コンテナID>
```
