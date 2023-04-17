* 平均時間複雜度：$O(nlgn)$
* 不穩定排序
* worst case：$\theta(n^2)$
* best case：$\theta(nlgn)$ $\leftarrow$ 平均狀況接近這個
* 核心觀念：Divide and couquer，選定一個pivot，將所有元素與pivot比較，如果小於pivot就放到前面(因為快速排序是從小到大)
* 通常看average case,因為通常狀況比較接近平均狀況O(nlgn)
* ![[Screenshot_20230416_113243.jpg]]
* i 紀錄陣列中> pivot的值的位置，在i左邊的都 < pivot
* 最右邊為pivot(x) , p為最左 , j一直向右檢視, i 留在左方等待交換
* 證明快速排序平均接近$\theta(nlgn)$：
	* 只要分割比例是一個常數，對於漸進符號來說對數的情況並不重要
	* 任何常數比例的對數都會產生深度為$\theta(nlgn)$的遞迴樹