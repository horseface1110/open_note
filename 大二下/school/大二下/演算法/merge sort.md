* 時間複雜度：$O(nlog^n)$
* 最佳時間複雜度：$O(nlog^n)$，已排序好的陣列
* 最差時間複雜度：$O(nlog^n)$，倒轉陣列
* 核心觀念：divid and counter，兩個子陣列元素比較大小，放入陣列直到全部。
* 可以以範例來思考
``` 
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |     <- index
---------------------------------
  p           q                r      <- 可以知道為什麼first = p - q + 1，還有為什麼放入新陣列時，F[]要+1，S[]不用
```
* 虛擬碼
```
Merge_Sort(A,p,r)
	q = (p + r) / 2
	Merge_Sort(A,p,q)        -> 因為q是包下面，所以這樣分可以平分
	Merge_sort(A,q + 1,r)
	Conbine(A,p,q,r)


流程：創兩個新陣列儲存元素，兩個陣列最後一個放無限
	 從兩個新陣列比較，放回母陣列原本的位置  

 Conbine(A,p,q,r)
	first = q - p + 1
	second= r - q
	creat F[first + 1] and S[second + 1]

	for i=1 to first
		F[i] = A[p + i - 1]
	for i=1 to second
		S[i] = A[q + i]
	F[first + 1] = ∞
	S[second+ 1] = ∞

	i = 1 
	j = 1 
	for k=p to r
		if F[i] < S[j]
			A[k] = F[i]
			i++
		else 
			A[k] = S[j]
			j++