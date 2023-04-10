### f(n) [] g(n)
* $O$
	* f(n) < g(n)
	* 當n > $n_0$時，對某些c成立時成立
* $\Omega$
	* f(n) > g(n)
	* 當n > $n_0$時，對某些c成立時成立
* $o$
	* f(n) < g(n)
	* 當n > $n_0$時，對**所有**c都成立時成立
	* 驗證方式：$\lim_{0 \to \infty} \frac{f(n)}{g(n)}$ = 0  
* $\omega$
	* f(n) > g(n)
	* 當n > $n_0$時，對**所有**c都成立時成立
	* 驗證方式：$\lim_{0 \to \infty} \frac{f(n)}{g(n)}$ = $\infty$
* $\Theta$
	* $c_1g(n)$ $\leq$ $f(n)$ $\leq$ $c_2g(n)$

#### big 跟 small 的差別
big :     對某些成立就好，較為鬆散
small: 對所有都成立才行，較嚴格