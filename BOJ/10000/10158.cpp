#include<stdio.h>
int main() {
	int w, h, p, q, t, x, y;
	scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);
	x = (p + t) % (2 * w);
	y = (q + t) % (2 * h);
	if (x / w)x = w - x % w;
	if (y / h)y = h - y % h;
	printf("%d %d", x, y);
}
//#include<iostream>
//using namespace std;
//
//int main() {
//	int w, h;
//	int xpos, ypos;
//	int t;
//	int dx = 1;
//	int dy = 1;
//
//	scanf("%d %d", &w, &h);
//	scanf("%d %d", &xpos, &ypos);
//	cin >> t;
//
//	while (t--) {
//		if (xpos == w || xpos == 0)
//			dx = -dx;
//		if (ypos == h || ypos == 0)
//			dy = -dy;
//		xpos += dx;
//		ypos += dy;
//	}
//	cout << xpos << ' ' << ypos << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int w, h;
//	cin >> w >> h;
//	int p, q;
//	cin >> p >> q;
//	int t;
//	cin >> t;
//	int status = 1;	//1:x+1,y+1. 2:x+1,y-1, 3:x-1,y+1 4:x-1,y-1
//	int gap = 0;
//	while (t > gap) {
//		switch (status)
//		{
//		case 1:
//			gap = (abs(w - p) <= abs(h - q)) ? abs(w - p) : abs(h - q);
//			p += gap; q += gap; 
//			status = (p == w) ? ((q==h)?4:3) : 2;//¿À¸¥ÂÊÀ§¸ð¼­¸® : ¿À¸¥ÂÊ ºÎµúÈû : À§ÂÊ ºÎµúÈû
//			break;
//		case 2:
//			gap = (abs(w - p) <= abs(0 - q)) ? abs(w - p) : abs(0 - q);
//			p += gap; q -= gap;
//			status = (p == w) ? ((q == 0) ? 3 : 4) : 1;//¿À¸¥ÂÊ¾Æ·¡¸ð¼­¸® : ¿À¸¥ÂÊ ºÎµúÈû : ¾Æ·¡ÂÊ ºÎµúÈû
//			break;
//		case 3:
//			gap = (abs(0 - p) <= abs(h - q)) ? abs(0 - p) : abs(h - q);
//			p -= gap; q += gap;
//			status = (p == 0) ? ((q == h) ? 2 : 1) : 4;//¿ÞÂÊÀ§¸ð¼­¸® : ¿ÞÂÊ ºÎµúÈû : À§ÂÊ ºÎµúÈû
//			break;
//		case 4:
//			gap = (abs(0 - p) <= abs(0 - q)) ? abs(0 - p) : abs(0 - q);
//			p -= gap; q -= gap;
//			status = (p == 0) ? ((q == 0) ? 1 : 2) : 3;//¿ÞÂÊ¾Æ·¡¸ð¼­¸® : ¿ÞÂÊ ºÎµúÈû : ¾Æ·¡ÂÊ ºÎµúÈû
//			break;
//		}		
//		t -= gap;
//	}
//	for (int i = 0; i < t; i++) {
//		switch (status)
//		{
//		case 1:
//			p += 1; q += 1;
//			status = (p == w) ? ((q == h) ? 4 : 3) : 2;//¿À¸¥ÂÊÀ§¸ð¼­¸® : ¿À¸¥ÂÊ ºÎµúÈû : À§ÂÊ ºÎµúÈû
//			break;
//		case 2:
//			p += 1; q -= 1;
//			status = (p == w) ? ((q == 0) ? 3 : 4) : 1;//¿À¸¥ÂÊ¾Æ·¡¸ð¼­¸® : ¿À¸¥ÂÊ ºÎµúÈû : ¾Æ·¡ÂÊ ºÎµúÈû
//			break;
//		case 3:
//			p -= 1; q += 1;
//			status = (p == 0) ? ((q == h) ? 2 : 1) : 4;//¿ÞÂÊÀ§¸ð¼­¸® : ¿ÞÂÊ ºÎµúÈû : À§ÂÊ ºÎµúÈû
//			break;
//		case 4:
//			p -= 1; q -= 1;
//			status = (p == 0) ? ((q == 0) ? 1 : 2) : 3;//¿ÞÂÊ¾Æ·¡¸ð¼­¸® : ¿ÞÂÊ ºÎµúÈû : ¾Æ·¡ÂÊ ºÎµúÈû
//			break;
//		}
//	}
//	cout << p <<' '<< q;
//	return 0;
//}