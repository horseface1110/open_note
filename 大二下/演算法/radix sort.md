* 時間複雜度：$\theta$(dn)   <- d回conuting sort，一回counting sort有 (n+k) ，又k = $O(n)$
* 虛擬碼
```
radix-sort(A,d)   <- d 是有幾個bit
	use counting sort to sort A array on digit i
```
* 如何把數值分成bit：結論 => r = $lgn$ 最好( r 是 以多少bit切)
* 切的時間複雜度為：$\theta(\frac{b}{r}(n+2^r))$
* 