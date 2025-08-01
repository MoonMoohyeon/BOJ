# [Gold V] 배열 탈출 - 11909 

[문제 링크](https://www.acmicpc.net/problem/11909) 

### 성능 요약

메모리: 41136 KB, 시간: 1308 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 최단 경로, 데이크스트라

### 제출 일자

2025년 7월 25일 16:00:23

### 문제 설명

<p>상수는 2차원 배열 A[1..n][1..n] (n≥2, n은 자연수)을 가지고 있습니다. 이 배열의 각 원소는 1 이상 222 이하의 정수입니다.</p>

<p>배열을 가지고 놀던 상수를 본 승현이는, 질투심이 불타올라 상수를 A[1][1]에 가둬 버렸습니다! 최소한의 양심이 있던 승현이는 A[n][n]에 출구를 만들어 놓고 이 사실을 상수에게 알려줬습니다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11909/1.png" style="height:164px; width:203px"></p>

<p style="text-align: center;">[그림 1] n=4라면 상수는 A[1,1]에 있고, 출구는 A[4][4]에 있습니다.</p>

<p>상수는 가능한 한 빨리 출구인 A[n][n]에 도달하고자 합니다. 상수가 A[i][j]에 있다고 가정했을 때, 상수는 최단 경로로 이동하기 위해 아래와 같은 조건을 만족하며 이동합니다.</p>

<ol>
	<li>1≤i,j<n이라면, 상수는 A[i][j+1] 또는 A[i+1][j]로만 건너갑니다.</li>
	<li>i=n,1≤j<n이라면, A[i][j+1]로만 건너갑니다.</li>
	<li>1≤i<n,j=n이라면 A[i+1][j]로만 건너갑니다.</li>
	<li>i=j=n인 경우 바로 출구로 갑니다.</li>
</ol>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11909/2.png" style="height:190px; width:234px"></p>

<p style="text-align: center;">[그림 2] n=5라고 가정합시다. (ㄱ)는 1번 조건을 만족하고, (ㄴ)는 2번 조건을 만족하며, (ㄷ)는 3번 조건을 만족합니다.</p>

<p>그러나 건너갈 때에도 제약이 따릅니다. 상수가 A[a][b]에서 A[c][d]로 건너가려면 A[a][b]>A[c][d]를 만족해야 합니다. 상수는 왜인지 이런 조건을 만족하면서 이동할 수 없을 것 같았습니다. 다행히도, 승현이가 상수를 배열에 가둬버리기 전에, 상수는 배열의 각 원소에 버튼을 만들어 놓아서, 이 버튼을 누르면 해당 원소의 값이 1 증가하도록 했습니다. (물론 상수는 자신이 위치해 있는 원소의 버튼만 누를 수 있습니다.) 이 버튼 덕분에, 상수는 항상 배열을 탈출할 수 있습니다!</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11909/3.png" style="height:98px; width:122px"></p>

<p style="text-align: center;">[그림 3] n=2라고 가정합시다. A[1][1]=5>A[1][2]=2이므로, 상수는 A[1][1]에서 A[1][2]로 건너갈 수 있습니다. 상수가 A[1][1]에서 A[2][1]로 건너가려면, A[1][1]에 있는 버튼을 두 번 눌러 A[1][1]의 값을 7로 만들면 됩니다.</p>

<p>하지만 버튼을 한 번 누르는 데에는 1원의 비용이 듭니다. 상수는 돈을 가능한 한 적게 들이면서 배열을 탈출하고자 합니다. 상수를 도와주세요.</p>

### 입력 

 <p>첫 번째 줄에 n이 주어집니다. (n ≤ 2,222)</p>

<p>다음에 n개 줄이 주어집니다. 이 중 i(1≤i≤n)번째 줄에는 n개의 수 A[i][1],A[i][2],⋯,A[i][n−1],A[i][n]이 공백을 사이로 두고 차례대로 주어집니다.</p>

### 출력 

 <p>첫 번째 줄에 상수가 배열을 탈출하기 위해 들여야 할 최소 비용(원 단위)을 출력합니다.</p>

<p> </p>

