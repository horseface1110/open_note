這一個 section 要提出另一個演算法叫作 SELECT，它的時間複雜度也是 $O(n)$，不過它跟 RANDOMIZED-SELECT 最大的不同就是它保證每次的 partition 都是好的 split。  
假設 input array 的長度是 n(n > 1)，如果長度為1的話，那 SELECT 會回傳它唯一的那個元素，這也是 recursive call 終結的條件。  
1.  把這個 array 每 5 個 elements 就分成一個 group，所以會有 $\lfloor n/5 \rfloor$ 個長度為 5 的 groups，然後剩下不足 5 的 elements 就自己獨立成一個 group。  
2. 各組分開作 insertion sort，然後把各組的 median 取出來變成一個 array。  
3. 把這個 median 的 array，call 一次 SELECT，找出這個 array 的 median。我們把這個"median 的 median"叫作 _x_。  
4. 以 _x_ 當作 pivot，把整個 input array 跑過一次 PARTITION，分成左右兩邊，假設左邊有 _k_ - 1 個 elements，中間是 pivot _x_，那麼右邊就應該會有 _n_ - _k_ 個 elements。  
5. 如果要找 ith order statistic 剛好是 pivot x 的話，那就回傳 x，否則我們看這個 order statistic 是落在右邊還是左邊，我們就 call SELECT 下去找。(當然啦，如果在右邊的話，就要找 (i - k)th order statistic)  
  
  
SELECT **的時間複雜度**  

[![](https://2.bp.blogspot.com/_X8JIptbFsbk/TRsKac_xfVI/AAAAAAAAACQ/5c5bxt2aPPc/s320/median_select.png)](https://2.bp.blogspot.com/_X8JIptbFsbk/TRsKac_xfVI/AAAAAAAAACQ/5c5bxt2aPPc/s1600/median_select.png)
如上圖，每個 element 都表示成一個點，每一個 column 就代表一個 group，白色的點是該 group 的 median，標示成 _x_ 的就是 median 的 median。因為我們假設每個 element 都是相異的，所以至少有一半以上的 median 都會比 _x_ 還要來的大。除了 _x_ 自己這個 group 和最後一個 group 之外，其他每個 group 都會有 3 個 elements 比 _x_ 還要大，所以我們可以得到：至少有  
$$3(\lceil\frac{1}{2}\lceil\frac{n}{5}\rceil\rceil - 2) \geq \frac{3n}{10} - 6$$  
個 elements 比 _x_ 大，同理，有 $$\frac{3n}{10} - 6$$ 個 elements 比 _x_ 小。因此，SELECT 在第 5 個步驟的 recursive call 最多只有 $$\frac{7n}{10} + 6$$ 個 elements 而已。  
令 $T(n)$ 為 SELECT 跑在 array 長度為 n 時所需要的時間，並且假設 $T(n)$ 是遞增的。  
第一步需要 $O(n)$ 的時間，  
第二步需要 $O(n)$ 的時間(不用懷疑，5 個 elements 的 insertion sort 我們可以視為 $O(1)$)，  
第三步需要 $T(\lceil n/5 \rceil)$ 的時間，  
第四步需要 $O(n)$ 的時間，  
第五步最多需要 $T(7n/10 + 6)$ 的時間，  
於是我們可以整理出如下的遞迴式：  
[](http://www.codecogs.com/eqnedit.php?latex=T%28n%29%20%5Cleq%20%5Cleft%5C%7B%5Cbegin%7Barray%7D%7Bll%7D%20%5CTheta%281%29%20&%20%5Cmbox%7Bif%20%7D%20n%20%5Cleq%20140%5C%5C%20T%28%5Clceil%20n/5%20%5Crceil%29%20@plus;%20T%287n/10%20@plus;%206%29%20@plus;%20O%28n%29%20&%20%5Cmbox%7Bif%20%7D%20n%20%3E%20140%20%5Cend%7Barray%7D%5Cright.)[![](https://lh3-testonly.googleusercontent.com/blogger_img_proxy/AByxGDShUIdWc9WvmdiHcFs6SE3xgPhA2N2EnYlDrAK10YluFLuebYWnSvPR3s5_IalbwWZoiMiivDXrN_j6-Do7crFuVC0mpHTHoTW0On_0-1Sm04VUHc0NXNcpPAexE1G9Tykbunuq7CrVIwtH8RN6DPEjA-qQwcLBe0Gyzj6OafNAQhMP3dvJ4xjD_PcuGYBfNH8oAdNI81pVYLGYeTC_AISMDK9z5j1Gz8QwQcvdMnFPNyO31RSjzHjMUd9gCjgtNXtXnmL6iUB8zsOTpfOWqMCdW5FgGxdg46zPpBMtmnmbB9n8_OwZTCEnfeAyjUsm2zRxoSyWq7ocOJtqmYhrBoV5GM7fPdbPmUgs6KSI31Cfg9pKgdWN=s0-d "T(n) \leq \left\{\begin{array}{ll} \Theta(1) & \mbox{if } n \leq 140\\ T(\lceil n/5 \rceil) + T(7n/10 + 6) + O(n) & \mbox{if } n > 140 \end{array}\right.")](http://www.codecogs.com/eqnedit.php?latex=T%28n%29%20%5Cleq%20%5Cleft%5C%7B%5Cbegin%7Barray%7D%7Bll%7D%20%5CTheta%281%29%20&%20%5Cmbox%7Bif%20%7D%20n%20%5Cleq%20140%5C%5C%20T%28%5Clceil%20n/5%20%5Crceil%29%20@plus;%20T%287n/10%20@plus;%206%29%20@plus;%20O%28n%29%20&%20%5Cmbox%7Bif%20%7D%20n%20%3E%20140%20%5Cend%7Barray%7D%5Cright.)  
看到上面的 140 了嗎？這個神奇的數字怎麼來的呢？慢慢來。  
還是利用 substitution method，假設 $T(n) \leq cn$，$O(n) \leq an$，其中 _a_, _c_ 各為一個常數。接著代進去原來的式子中：  
[![](https://lh3-testonly.googleusercontent.com/blogger_img_proxy/AByxGDRuGKD5P9yFhiYV2Q8CGLUEgfmqRlo4fJw5_4jQF5kf1ScsICsnm58P5o8cNQPNY0qlH5hWuoCLkLlVP9Xel-JgnTWhn-an7wd8nv0zsqq0jBuKqtHjFQ5X4-ENnHgBzcIU0An56Cr_UuX3ikcwlzfqWdIDz_UKFjB7Vu2kH6K3KGcDkmx3C3h0cYh61CSiIjLja511oh-5lzhTQEDUv5w7I3Lv09acAEJiDBbnb2F_Ki78aGZ13xhMCNK3ItUaRUf-UvOs6JZEVyk-4RMASiJhw5SRfn3EkEQbCeE5IQz2mqd_sB73fj9vPI0B6Pet4rJjhudoZnjYpXBB5fPiWlnCU76XxXmGsiKiMB_eI6tpsmV2AuBbqN4UF4zwwgWx=s0-d "\begin{align*} T(n) &\leq c \left \lceil n/5 \right \rceil + c(7n/10 + 6) + an\\ &\leq cn/5 + c + 7cn/10 + 6c + an\\ &= 9cn/10 + 7c + an\\ &= cn + (-cn/10 + 7c + an) \end{align*}")](http://www.codecogs.com/eqnedit.php?latex=%5Cbegin%7Balign*%7D%20T%28n%29%20&%5Cleq%20c%20%5Cleft%20%5Clceil%20n/5%20%5Cright%20%5Crceil%20@plus;%20c%287n/10%20@plus;%206%29%20@plus;%20an%5C%5C%20&%5Cleq%20cn/5%20@plus;%20c%20@plus;%207cn/10%20@plus;%206c%20@plus;%20an%5C%5C%20&=%209cn/10%20@plus;%207c%20@plus;%20an%5C%5C%20&=%20cn%20@plus;%20%28-cn/10%20@plus;%207c%20@plus;%20an%29%20%5Cend%7Balign*%7D)  
只要 $-cn/10 + 7c + an \leq 0$，$T(n)$ 最多就是 $cn$ 而已。所以 $c \geq 10a(n/(n-70))$ 只要在 $n \geq 70$的情況下都會滿足，而且因為我們假設 $n \geq 140$，我們會得到 $n/(n-70) \leq 2$，所以只要 $c \geq 20a$ 的話，$-cn/10 + 7c + an$ 就會小於等於 0。所以其實 140 這個數字並不是那麼的神奇，我們可以任意指定它為一個大於 70 的數字，然後再為此挑一個適當的 _c_ 就可以了。因此我們得證 SELECT 是 $O(n)$ 的演算法。