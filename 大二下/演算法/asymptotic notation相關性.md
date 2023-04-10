* $\theta$()是雙向的，f(n) = $\theta$g(n) $\Longleftrightarrow$g(n) = $\theta$f(n)
* $\theta$ 在等號左右邊的意義
	* 左邊：對全部案例成立
		* ex. $3n^2$ $+$ $\theta$$(n)$ = $\theta(n^2)$
		* 上式意義為：對所有f(n) $\in$  $\theta$$(n)$ 存在g(n) $\in$ $\theta(n^2)$，亦即$3(n^2)$ + f(n) = g(n)
	 * 右邊：對部份案例成立
		 * ex.$3n^2$ $+$ $2n$ $+$ $1$= $3n^2$ $+$ $\theta(n)$ 
		 * 上式意義為：有一些$f(n)$ $\in$ $\theta(n)$ 使之成立
* Refexivity反身性：自己是自己的......：$O$ $\Omega$ $\Theta$
* Transitivity遞移性：$O$ $\Omega$ $\Theta$ $o$ $\omega$
* Symmetry對稱性：f 、g的位置必須可以互換：$\theta$
* Transpose Symmetry轉置對稱性：角色、關係可以全部相反：$O$ $\leftrightarrow$ $\Omega$ 、$o$ $\leftrightarrow$ $\omega$ 