* file distribution：
	* server：
		* 送一個檔案的時間：F / $u_s$
		* 送多個檔案的時間：N*F / $u_s$
	 * client：
		* $d_{min}$ ：client最小下載速率
		* 最大下載時間：F / $d_{min}$
則這方式傳輸花的時間 >=  max(NF/$u_s$ , F/$d_{min}$)     $\leftarrow$ N是因為S要送給N個C