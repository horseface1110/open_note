asm(
	"組語的code，\\n\\t"   $\leftarrow$ 可以很多行
	: output  [第一行的變數名稱] "r" (程式的變數)      $\leftarrow$ 如果沒用到變數名稱就不用放
	: input    [第一行的變數名稱] "r" (程式的變數)  , [第一行的變數名稱] "r" (程式的變數)    $\leftarrow$ 連接用逗號。
	: 用到的占存器 ex. "x18"   $\leftarrow$ ""要加
);
* output那邊如果是write only的話，必須加 "="