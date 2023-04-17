* 就是proxy
* 計算名詞：
	* access link rate：瓶頸線路傳輸
	* web object size：封包大小
	* average request rate from browsers to origin servers：送封包的速率(每秒幾個)
	* access link utilization：瓶頸線路利用率( > 0.7就算大)
	* end to end delay：internet delay + access link delay(同常是這個在拖) + LAN delay
* 計算：
	* 線路使用率：流量/線路大小 $\rightarrow$ web object size * average request rate / access link rate
	* 若有catch：流量 = 原流量 * (1 - 占存比率)