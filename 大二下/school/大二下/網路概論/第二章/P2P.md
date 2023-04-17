* 去中心化，沒有統一的server
* client各自以ip互聯

* file distribution：
	* server：
		* 送一個檔案的時間：F / $u_s$
	 * client：
		* $d_{min}$ ：client最小下載速率
		* 最大下載時間：F / $d_{min}$
	 * 但此時所有client端也會上傳的他們的檔案，所以整個系統上傳量是N*F
故總時間 = max( F/ $u_s$ , F / $d_{min}$ , NF / ($u_s$ , $u_1$ , $u_2$ ,......))