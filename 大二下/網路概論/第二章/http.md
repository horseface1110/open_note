* 超文字傳輸協定
* 是"statless"，視每個請求都是來自不同的機器
* 兩種連線方式：
	1. Non-persistent http：使用TCP發起連線，連上後一個請求只能傳遞一個檔案
	2. persistent http：使用TCP發起連線，連上後一個請求可以同時要求多個檔案
* 流程：
	 1. Nom-persistent http：
		 * C：發起連線，S：通知C說ok了，C：發送要求要一個檔案，S：給他然後結束，C：重複步驟直到所有檔案要完
		 * 時間：發起到收到回覆：RTT。2RTT+傳輸檔案時間
	 1. persistent http(http1.1)：
		 * 到上述第四步時不結束，繼續保持連線狀態，客戶端送要求時就送檔案回去
		 * 時間：1RTT。