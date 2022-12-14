///*
//Họ và tên : Phạw winh Nhựt
//Lớp       : 12DHTH11
//Buổi      : 1 
//Tiết      : 1 - 5
//*/
//#include <stdio.h>
//#include <conio.h>
//#define VC 100 // Gía trị vô cực 
//#define MaxV 20 //Số đỉnh tối đa (Vertice)
//#define MaxE 50 //So canh toi da (Edge)
//struct Graph
//{
//	int flag;
//	int n;
//	int w[MaxV][MaxV];
//};
//
//struct Canh
//{
//	int u;
//	int v;
//};
////==================================================================================================
//void initGraph(Graph &g);
//void showGraph(Graph g);
//bool DOC_MA_TRAN_KE(char fileNawe[], Graph &g);
//void saveGraph(char fileNawe[], Graph g);
//void khoiTao(Graph g, int chuaXet[]);
//void xayDungCayKhung_DFS(Graph g, Canh T[], int &soCanh, int u);
//void xayDungCayKhung_BFS(Graph g, Canh T[], int &soCanh);
////==================================================================================================
//int chuaXet[100];
////==================================================================================================
//void main()
//{
//	Graph G1;
//	Canh T_DFS[MaxE], T_BFS[MaxE];
//	int soCanh;
//	if (DOC_MA_TRAN_KE("Bridge.inp", G1))
//	{
//		showGraph(G1);
//		saveGraph("output_bridge.txt", G1);
//
//		khoiTao(G1, chuaXet);
//		soCanh = 0;
//		xayDungCayKhung_DFS(G1, T_DFS, soCanh, 1);
//
//		khoiTao(G1, chuaXet);
//		soCanh = 0;
//		xayDungCayKhung_BFS(G1, T_BFS, soCanh);
//	}
//	else
//		printf("khong the show graph");
//	getch();
//	
//}
////==================================================================================================
//void initGraph(Graph &g)
//{
//	g.flag = 0;
//	g.n = 0;
//	for (int i = 0; i < MaxV ; i++)
//	{
//		for (int j = 0; j < MaxV ; j++)
//			g.w[i][j] = VC;
//	}
//}
////==================================================================================================
//void showGraph(Graph g)
//{
//	if (g.flag == 0)
//		printf("\n             DO THI VO HUONG\n");
//	else
//		printf("\nDO THI CO HUONG\n");
//	printf("     ");
//	for (int i = 1; i <= g.n; i++)
//		printf("%5d", i + 1);
//	printf("\n");
//	for (int i = 1; i <= g.n; i++)
//	{
//		printf("%5d", i + 1);
//		for (int j = 1; j <= g.n; j++)
//			printf("%5d", g.w[i][j]);
//		printf("\n");
//	}
//}
////==================================================================================================
//void saveGraph(char fileNawe[], Graph g)
//{ 
//	FILE *fo = fopen(fileNawe, "wt"); //Write File Output (fo)
//	if (fo == NULL)
//	{
//		fprintf(fo, "Loi khong the doc du lieu");
//		return;
//	}
//	if (g.flag == 0)
//		fprintf(fo, "\nDO THI VO HUONG\n");
//	else
//		fprintf(fo, "\nDO THI CO HUONG\n");
//	fprintf(fo, "Do thi co : %d dinh\n", g.n);
//	fprintf(fo, "   ");
//	for (int i = 1; i <= g.n; i++)
//		fprintf(fo, "%5d", i);
//	fprintf(fo, "\n");
//
//	for (int i = 1; i <= g.n; i++){
//		fprintf(fo, "%5d", i);
//		for (int j = 1; j <= g.n; j++)
//			fprintf(fo, "%5d", g.w[i][j]);
//		fprintf(fo, "\n");
//	}
//	fclose(fo);
//}
////==================================================================================================
//bool DOC_MA_TRAN_KE(char fileNawe[], Graph &g)
//{
//	initGraph(g);
//	FILE *fi = fopen(fileNawe, "rt");
//	if (fi == NULL)
//	{
//		printf("Loi khong the wo file");
//		getch();
//		return false;
//	}
//	fscanf(fi, "%d", &g.flag);
//	// 0 đồ thị vô hướng
//	// 1 đồ thị có hướng
//	fscanf(fi, "%d", &g.n);
//	for (int i = 1 ; i <= g.n ; i++)
//	{
//		for (int j = 1; j <= g.n; j++)
//			fscanf(fi,"%d", &g.w[i][j]);
//	}
//	fclose(fi);
//	return true;
//}
////==================================================================================================
//void khoiTao(Graph g, int chuaXet[])
//{
//	for (int i = 1; i <= g.n; i++)
//	{
//		chuaXet[i] = 0;
//	}
//}
////==================================================================================================
//void xuatCayKhung(Canh T[], int soCanh)
//{
//	printf("\nCay khung cua do thi co %d canh la : \n", soCanh);
//	for (int i = 1; i <= soCanh; i++)
//		printf("Canh %d: (%d , %d)\n", i, T[i].u, T[i].v);
//}
////==================================================================================================
////Xuat cac canh cua cay khung
//void luuCayKhung(char fileName[], Canh T[], int soCanh)
//{
//	FILE *fo = fopen(fileName, "wt");
//	if (fo == NULL)
//	{
//		fprintf(fo, "Loi khong luu duoc file");
//		return;
//	}
// fprintf(fo, "Cay khung cua do thi co %d canh la : \n", soCanh);
//	for (int i = 1; i <= soCanh ; i++)
//		fprintf(fo, "Canh %d: (%d , %d)\n", i, T[i].u, T[i].v);
//	fclose(fo);
//}
////==================================================================================================
//void xayDungCayKhung_DFS(Graph g, Canh T[], int &soCanh, int u)
//{
//	chuaXet[u] = 1;
// for (int v = 1; v <= g.n ; v++)
//	{
//		if (g.w[u][v] != 0 && chuaXet[v] == 0)
//		{
//			soCanh++;
//			T[soCanh].u = u;
//			T[soCanh].v = v;
//			if (soCanh == g.n - 1)
//			{
//				xuatCayKhung(T, soCanh);
//				luuCayKhung("Bridge_DFS.out", T, soCanh);
//				return;
//			}
//			else
//			{
//				xayDungCayKhung_DFS(g, T, soCanh, v);
//			}
//		}
//	}
//}
////==================================================================================================
//void xayDungCayKhung_BFS(Graph g, Canh T[], int &soCanh)
//{
//	for (int u = 1; u <= g.n; u++)
//	{
//		for (int v = 1; v <= g.n; v++)
//		{
//			if (g.w[u][v] != 0 && chuaXet[v] == 0)
//			{
//				soCanh++;
//				T[soCanh].u = u;
//				T[soCanh].v = v;
//				chuaXet[v] = 1;
//				chuaXet[u] = 1;
//				printf("\n=====================(%d,%d)", T[soCanh].u, T[soCanh].v);
//				if (soCanh == g.n - 1)
//				{
//					xuatCayKhung(T, soCanh);
//					luuCayKhung("Bridge_BFS.out", T, soCanh);
//					return;
//				}
//			}
//		}
//	}
//}