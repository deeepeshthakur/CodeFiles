#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

// bool didMount=true;
vector<int> dp{1, 2, 4, 8, 13, 21, 31, 45, 66, 81, 97, 123, 148, 182, 204, 252, 290, 361, 401, 475, 565, 593, 662, 775, 822, 916, 970, 1016, 1159, 1312, 1395, 1523, 1572, 1821, 1896, 2029, 2254, 2379, 2510, 2780, 2925, 3155, 3354, 3591, 3797, 3998, 4297, 4433, 4779, 4851, 5123, 5243, 5298, 5751, 5998, 6374, 6801, 6925, 7460, 7547, 7789, 8220, 8503, 8730, 8942, 9882, 10200, 10587, 10898, 11289, 11614, 11876, 12034, 12931, 13394, 14047, 14534, 14901, 15166, 15688, 15972, 16619, 17355, 17932, 18845, 19071, 19631, 19670, 20722, 21948, 22526, 23291, 23564, 23881, 24596, 24768, 25631, 26037, 26255, 27219, 28566, 29775, 30094, 31311, 32217, 32620, 32912, 34277, 35330, 35469, 36204, 38647, 39160, 39223, 39943, 40800, 41882, 42549, 43394, 44879, 45907, 47421, 47512, 48297, 50064, 50902, 52703, 52764, 54674, 55307, 56663, 58425, 59028, 60576, 60995, 62205, 63129, 64488, 66999, 67189, 68512, 68984, 70170, 71365, 75618, 76793, 77571, 79047, 80309, 83179, 84345, 87016, 87874, 88566, 89607, 91718, 92887, 93839, 95103, 97974, 99583, 101337, 102040, 103626, 104554, 106947, 107205, 108622, 111837, 112800, 113949, 114642, 116291, 117177, 121238, 125492, 126637, 129170, 130986, 131697, 134414, 134699, 136635, 139964, 143294, 144874, 146605, 147499, 148593, 150146, 152318, 152834, 156836, 157150, 160782, 163010, 163502, 164868, 170984, 172922, 174171, 177853, 180249, 182071, 185403, 188314, 190726, 190894, 193477, 196832, 199646, 201472, 202699, 205325, 206811, 208748, 214435, 217182, 218011, 225350, 226682, 229163, 231694, 233570, 234619, 235152, 238727, 240814, 247822, 253857, 254305, 260433, 261620, 262317, 266550, 269195, 271511, 274250, 274753, 280180, 284289, 290005, 293034, 295037, 296506, 298414, 302663, 305782, 308841, 317739, 321173, 323672, 324806, 329181, 331018, 336642, 340901, 343359, 347001, 348110, 348899, 362520, 366119, 368235, 370696, 371542, 377450, 380366, 382012, 382245, 384957, 387479, 390518, 391462, 399174, 403920, 411847, 412671, 416880, 417991, 422453, 433973, 434773, 440619, 441148, 443779, 446065, 456289, 458426, 462402, 470670, 474668, 475800, 481476, 482868, 498435, 501084, 508193, 511258, 514644, 524307, 527197, 535369, 536903, 538331, 542020, 555275, 564016, 566106, 567408, 572027, 582478, 583407, 585871, 593257, 596837, 598426, 599784, 607794, 610404, 621790, 624574, 627703, 633442, 640047, 648858, 659179, 663558, 667337, 672815, 673522, 686013, 691686, 693169, 694279, 696931, 703162, 711364, 723249, 729860, 731008, 739958, 740124, 744403, 753293, 768134, 770113, 773912, 779917, 787407, 794900, 797567, 800658, 813959, 814414, 827123, 829129, 839728, 847430, 850695, 851627, 862856, 880796, 884725, 889285, 896691, 897160, 904970, 909586, 915254, 922852, 935695, 937825, 938876, 959937, 961353, 964857, 970227, 976356, 980581, 986799, 1008106, 1009835, 1016906, 1020306, 1028612, 1033242, 1036012, 1042818, 1050881, 1051783, 1060844, 1086402, 1092043, 1096162, 1103456, 1123464, 1134057, 1136410, 1144080, 1145152, 1147774, 1156687, 1164278, 1166255, 1174751, 1187057, 1195316, 1201262, 1207345, 1212654, 1218610, 1225019, 1227887, 1240777, 1247071, 1258235, 1265462, 1274089, 1279515, 1288613, 1298980, 1306248, 1326918, 1333809, 1341190, 1343482, 1367480, 1372734, 1374779, 1384952, 1388147, 1394240, 1395346, 1409612, 1417336, 1418943, 1423296, 1446209, 1448494, 1462599, 1468933, 1474698, 1496110, 1502217, 1508335, 1513944, 1549693, 1552361, 1558304, 1567726, 1578307, 1593543, 1594370, 1596552, 1604567, 1611655, 1638201, 1657904, 1661549, 1668344, 1684653, 1700848, 1704061, 1712218, 1733148, 1744400, 1756959, 1766186, 1770297, 1774640, 1783782, 1790804, 1797186, 1819167, 1822095, 1835790, 1838687, 1840248, 1843265, 1858487, 1871701, 1874449, 1907155, 1933219, 1941873, 1953108, 1960964, 1970086, 1995385, 2005526, 2006388, 2012407, 2022419, 2027444, 2032071, 2046348, 2049691, 2081218, 2085045, 2107005, 2111011, 2117147, 2128804, 2130734, 2133565, 2163069, 2165643, 2183398, 2186582, 2200866, 2228833, 2238757, 2260397, 2287997, 2303690, 2306210, 2311079, 2319657, 2347177, 2348345, 2364629, 2380657, 2386691, 2392303, 2413369, 2429645, 2435861, 2445907, 2454603, 2461156, 2481207, 2493269, 2496558, 2526270, 2549274, 2559084, 2565601, 2571993, 2574622, 2589585, 2602736, 2606052, 2635578, 2636056, 2649712, 2667175, 2697913, 2705598, 2716472, 2726625, 2740640, 2748032, 2769317, 2773637, 2777175, 2796454, 2808141, 2818050, 2822209, 2828335, 2853048, 2858954, 2879003, 2898699, 2906226, 2928135, 2935468, 2950167, 2955230, 2959204, 2981209, 2999992, 3013106, 3016185, 3016728, 3033485, 3041287, 3046405, 3085842, 3097363, 3129048, 3137101, 3148974, 3153026, 3165425, 3172200, 3187649, 3208795, 3228028, 3239797, 3265353, 3281537, 3310390, 3330139, 3349916, 3351744, 3360950, 3366598, 3375910, 3382995, 3411775, 3438201, 3447140, 3453811, 3471520, 3485127, 3522748, 3569412, 3575690, 3578298, 3585562, 3593337, 3624737, 3626198, 3651501, 3667524, 3674434, 3675907, 3738616, 3754186, 3765841, 3786330, 3807381, 3818043, 3829535, 3831874, 3838373, 3862508, 3910613, 3942689, 3950184, 3954465, 3978469, 3992767, 4014701, 4032219, 4033924, 4065368, 4078004, 4089606, 4101646, 4119004, 4155098, 4166329, 4176904, 4182945, 4197748, 4211593, 4218728, 4253237, 4275441, 4288635, 4298689, 4301972, 4329866, 4357640, 4392330, 4403327, 4415543, 4434657, 4454780, 4460817, 4467239, 4489541, 4518764, 4526891, 4541320, 4560957, 4568090, 4582032, 4609341, 4631837, 4683082, 4688874, 4714962, 4728230, 4733954, 4744119, 4797763, 4819301, 4823437, 4850997, 4865482, 4886981, 4907820, 4931122, 4957782, 5005971, 5014678, 5031077, 5054902, 5059300, 5088659, 5119815, 5135680, 5153376, 5210102, 5213548, 5253584};

void solve(){
    int n;
    cin>>n;
    long long smm=0;
    for(int i=0;i<n;i++){
        cout<<dp[i]<< " ";
        smm+=dp[i];
    }
    cout<<"\n"<<smm<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}