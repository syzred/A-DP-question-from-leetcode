//输入一个形如
//2
//3 4
//6 5 7
//4 1 8 3
//的三角形。求出从顶层到底层走一遍、在“选取某一元素之后，只能在下一层选取与它相邻的两元素”这个条件下，元素之和最小的那条路径上元素值之和。

int main() {
	/***先输入一个二维容器，存储三角形元素***/
	vector<vector<int> > tri;
	int level;
	cin >> level;//输入三角形的层数
	int n;
	for (int i = 0; i < level; i++) {
		vector<int> a;
		for (int j = 0; j <= i; j++) {
			cin >> n;//对于特定的一层，输入每个元素的值
			a.push_back(n);
		}
		tri.push_back(a);
	}//三角形输入完毕
	
	/*状态转移方程是S(i,j)=min(S(i+1,j),S(i+1,j+1))+f(i,j)*/
	for (int row = level - 2; row >= 0; row--) {
		for (int col = 0; col <= row; col++) {
			tri[row][col] += min(tri[row+1][col],tri[row+1][col+1]);
		}
	}
	cout << tri[0][0];	
	return 0;
}
