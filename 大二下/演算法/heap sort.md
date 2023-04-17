### max-heapsort or min-heapsort
#### max-heapsort
* 平均時間複雜度：$O(n$$\lg$$n$)
* 最好時間複雜度：$O(n)$
* 最差時間複雜度：$O(n$$\log$$n$)$
* 空間複雜度：0
* 核心觀念：每一個node必大於子node小於父node。插入移除某個節點時，檢查子node，違反規則就交最大的子node換，再往下檢查。
* 虛擬碼：**index從0開始**
```
MAX-HEAPIFY(A,i,n)    <- A是陣列，i是要檢查的index，n是陣列長度
	l = Left(i)           <- Left()取得i的左子node的index
	r = Right(i)          <- Right()取得i的右子node的index
	
	if l <= n and A[l] > A[i]
		largest = l
	else 
		largest = i
	if r <= n and A[r] > A[largest]
		largest = r
	
	if largest != i
		exchange A[i] and A[largest]
		MAX-HEAPIFY(A,largest,n)


BUILD-MAX-HEAP(A,n)
	for i=n/2 to 0       <- 從最後一個非葉節點開始，而第一個葉節點是 n/2 + 1 
		MAX-HEAPIFY(A,i,n)	
```
* 精細時間複雜度分析：
	* h = $\lg^n$ : heap高度，
	* 每次呼叫MAX-HEAPIFY所須時間為$O(h)$
	* heap每層最多node數 < n / $2^{h+1}$
	* f(n) = $\sum_{i=0}^{h}$n / $2^{i+1}$ * $O(n)$   = $O(n$$\sum_{i=0}^{h}$$i/2^{i+1}$$)$
	* 將h -> $\infty$
	* f(n) <= $\sum_{h = 0}^{\infty}i/2^i$ = 2     <- 收斂
	* 得$O(n)$
* 相關操作
	* 取出最大值：
	* 
	```
	HEAP-EXTRACT-MAX(A,n)
		if n < 1
			return error
		max = A[0]
		A[0] = A[n]
		MAX-HEAPIFY(A,0,n-1)
		return max
	