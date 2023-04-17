* 客戶端請伺服器傳輸資料的方式的統稱
* 一些方法
	* POST：C把資源放到S去上傳/創造資源，不能被cache，上傳的東西在body裡
	* GET：C跟S要資源，可以被cache，要求的東西在url裡
	* HEAD：跟GET很像，差在他只會要求head而已，用來探測get會拿到什麼
	* PUT：跟POST很像，但重複呼叫PUT只會產生相同結果；重複呼叫POST會創造重複資源
	* [教學](https://www.w3schools.com/tags/ref_httpmethods.asp)
* status code
	* 1**：再等一下
	* 2**：成功
	* 3**：去其他地方
	* 4**：你挫賽了
	* 5**：我挫賽了
	* [教學](https://yakimhsu.com/project/project_w4_Network_http.html)

