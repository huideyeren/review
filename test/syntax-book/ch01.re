= 章見出し
//lead{
章にはリードが入ることがあります。図版や表が入ることはまずありませんが、@<b>{太字}くらいは使われることも。

複数段落になる可能性もあります。
//}
#@# 章見出しやリードの見た目については紙面次第ですが……。商業誌だとリードはゴチにしていることが多い？
#@# 部扉なしの場合は章扉あり、部扉ありの場合は章扉はあったりなかったり、という感じだが、一概には言えないし、デザインが絡むので厄介そう。部扉の背景に指定図版を貼り付けることがクラスファイル側でできるといいのかな
#@# 第X章 という書き方は、HTMLではi18n.yml/locale.ymlでカスタマイズ可能にしている

段落は普通に書き連ねていくだけです。段落間は空行を含めます。

こんなかんじ

です。空けない場合は、1つの
段落として結合されます。TeXと違って文字種によって良い塩梅にスペースを入れてくれたりはしないので、特に英文の場合は注意が必要です。this is a
pen.と「apen」になってしまいます。行頭行末のスペース文字も詰められてしまうので、
this is a pen.は途中改行せずに記述しなければなりません。

通常段落は「字下げ」することを想定して表現されますが、たとえばコードをまたぐ

//emlist{
'hello!' 'こんにちはWorld!'
//}
#@# コードリスト。紙面表現はアミカケがよいと思います。後出の例のようにキャプションが入ることもあります。また、インラインタグがこのリスト内で使われるので、単純なverbatimではまずいです。

//noindent
ようにしたい場合は、またいだ後の段落前に「@<tt>{//noindent}」を入れておくことで字下げを抑止できます（そもそもこういうまたぎ行為は筆者の好みではありませんが）。
#@# 字下げ抑止と本文中等幅の例

== 節見出し
@<tt>{=}の数で見出しレベルを表しますが、最大@<tt>{=====}の5レベルまでの見出しがあり得ます（内部的にはレベル6まであるけれども非推奨で、一部のビルダでは動かない）。

 * @<tt>{=}：章および部
 * @<tt>{==}：節
 * @<tt>{===}：項
 * @<tt>{====}：段
 * @<tt>{=====}：レベル5見出し

「X.X.X」のように採番するか否かは@<tt>{config.yml}の@<tt>{secnolevel}パラメータで変動します@<fn>{f1}。デフォルトは2（X.Xまで）ですが、このリファレンスドキュメントでは一応4（X.X.X.X）まで採番を試みています。
#@# FIXME:今のTeXレイアウトファイルだと設定によらずX.X.Xまでしか付かない？

//footnote[f1][前述したように@<tt>{PREDEF}、@<tt>{POSTDEF}の場合は採番@<b>{しません}。]

=== 項見出し……に脚注を入れると@<i>{TeX}ではエラー
@<fn>{f2}という脚注を見出し箇所に入れようとするとTeXではエラーになります。見出しにそういうものを入れるべきではない、といえばそれまでですが。見出しにはインラインでの装飾タグが入る可能性があります。

//footnote[f2][本当は項の脚注]

==== 段見出し
ここまで採番することがあるケースがあるか、というとたまにあったりします。

===== レベル5見出し
さすがにこのあたりのレベルは採番はしないですね。紙面では、:によるdescription箇条書きでは大きくなりすぎるような規模の場合にこのレベルの見出しを代用することがあります。

あくまでも見出しなので、見出しの行にそのまま段落が続いてしまう見た目は期待と違います。

== 長い節見出し■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
=== 長い項見出し■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
==== 長い段見出し■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
===== 長いレベル5見出し■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□

また、nonumあるいはnotocを付けた見出しは、章であっても採番されません。前者nonumは採番なし・目次に含める、後者notocは採番なし・目次にも含めないという意味です。

===[nonum] 採番しない項見出し

=== 採番する項見出し

nodispを付けると、紙面には表示されず目次には含まれる見出しとなります（採番なし）。節以下のレベルで使うことはほとんどなく、たとえば「献辞」のように紙面には見出しを出したくないけれども目次には入れておきたい前付名などに使うことを想定しています。

===[nodisp] nodispで隠れた見出し

== 箇条書き
=== ナカグロ箇条書き
ナカグロ箇条書き（HTMLの@<i>{ul}、TeXの@<i>{itemize}）は@<i>{スペース}+@<tt>{*}+@<i>{スペース}で表現します。インラインタグが含まれることがあります。

 * 箇条書き1
 * 箇条書き2@<b>{太字bold}@<i>{italicイタ}@<tt>{等幅code}

入れ子ナカグロ箇条書きもあります。

 * 箇条書き1
 ** 箇条書き1-1
 ** 箇条書き1-2
 *** 箇条書き1-2-1
 * 箇条書き2
 ** 箇条書き2-1

箇条書きの間に別の要素（ぶらさがりの段落など）が入ることは標準では対応しておらず、どうしてもそういうのが必要な場合は途中でフックして変換後ソースを書き換えることになります。

=== 番号箇条書き
番号箇条書き（HTMLの@<i>{ol}、TeXの@<i>{enumerate}）は@<i>{スペース}+@<tt>{数字.}+@<i>{スペース}で表現します。

 1. 箇条書き1
 2. 箇条書き2@<b>{太字bold}@<tt>{等幅code}

olnumで一応番号が変更可能なことを期待していますが、Webブラウザだとだめなことが多いかもしれません。

//olnum[10]

 10. 箇条書き10
 11. 箇条書き11

=== 用語リスト
用語リスト（HTMLの@<i>{dl}、TeXの@<i>{description}）は@<i>{スペース}+@<tt>{:}+@<i>{スペース}で見出しを、説明は行頭にタブかスペースを入れて表現します。

 : Alpha@<b>{bold太字}@<i>{italicイタ}@<tt>{等幅code}
	@<i>{DEC}の作っていた@<b>{RISC CPU}。@<i>{italicイタ}@<tt>{等幅code}
	浮動小数点数演算が速い。
 : POWER
	IBMとモトローラが共同製作したRISC CPU。@<br>{}
	派生としてPOWER PCがある。
 : SPARC
	Sunが作っているRISC CPU。
	CPU数を増やすのが得意。

//emlist{
@<b>{bold太字}@<i>{italicイタ}

 : Alpha@<embed>{@}<b>{bold太字}@<embed>{@}<i>{italicイタ}@<embed>{@}<tt>{等幅code}
        @<embed>{@}<i>{DEC}の作っていた@<embed>{@}<b>{RISC CPU}。@<embed>{@}<i>{italicイタ}@<embed>{@}<tt>{等幅code}
        浮動小数点数演算が速い。
 : POWER
        IBMとモトローラが共同製作したRISC CPU。@<embed>{@}<br>{}
        派生としてPOWER PCがある。
 : SPARC
        Sunが作っているRISC CPU。
        CPU数を増やすのが得意。@<balloon>{ふきだし説明}
//}
#@# コード内の太字およびイタリック。ttをコード内で使うのは無意味なので省略。
#@# embedは単純にその中のものを展開するだけなので、紙面的な特殊対応は不要。
#@# balloonは、本当は引き出し線+右寄せ にできるといいが…

説明文に複数の段落を入れることは構文上できないので、@<tt>{@}@<tt>{<br>{\}}を入れて改行することで代替します。

#@# コラム