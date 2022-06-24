# 備忘録

## 構想
あるkey文字で区切られた文字列に対して、  
文字を差し込み、key文字で閉じるコードを作りたい。  
ex)key文字：@、差し込み文字：AAA
XXX@YY@ZZ → XXX@YY@AAAA@ZZ

```mermaid
sequenceDiagram
participant 1 as main
participant 2 as CharSeparate
participant 3 as CharArrMerge

Note over 1: 初期文字設定

1->>+2: ポインター、初期文字、分割キー
alt ポインターに分割文字が追加される
2->>2: キーに基づいて文字分割
Note left of 1: 不具合1
  2->>1: voidで返す。
end

Note left of 1: 不具合２

1->>+3: ポインター、差し込み文字、差し込む場所、間に挟む文字
3->>3: 文字生成 
3->>1: 生成文字を返す。
```
↑完成できず

```mermaid
sequenceDiagram
participant 1 as main
participant 2 as charArrInsertWord

Note over 1: 初期文字,ポインター

1->>+2: ポインター、初期文字、分割キー
2->>2: 分割キーに基づいて文字分割
2->>2: 分割文字をポインターに追加
2->>1: 0正常、０以外異常
```
↑完成

## 不具合
1. CharSeparateで分割した配列の０列目が空？？？  
一旦無かったことに
1. CharArrMergeで↓のエラーメッセージが出る。  
一旦無かったことに  
ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

1. ~~resultの先頭にaが入る。~~  
**resultに初期値入れると解決**
```
ptr WWWW count 0
ptr XXX count 1 
ptr YY count 2
ptr Z.csv count 3
ptr (null) count 4
result aWWWW@XXX@YY@FLOW1@Z.csv
```

## 参考URL
[マークダウンでフローチャート](https://qiita.com/yoktave-yoknel/items/b923fe2b9206beab700c)  
[+α](https://shd101wyy.github.io/markdown-preview-enhanced/#/ja-jp/diagrams)