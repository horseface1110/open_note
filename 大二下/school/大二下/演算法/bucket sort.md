* 平均時間複雜度$O(n+k)$
* 最佳時間複雜度$O(n+k)$
* 最差時間複雜度$O(n^2)$
* 空間複雜度：$O(n+k)$
* 核心觀念：盡量均勻分配元素到每個箱子裡，箱子裡用insertion sort排序，這樣全部都排序好了
* 虛擬碼：
```
bucket soer(A , n)
for i = 0 to n
	insert A[i] into list B[ A[i] / k (向下取整)]
for i = 0 to k 
	sort list B[i] with insert sort 
```
* 證明時間複雜度：超麻煩，狗屎