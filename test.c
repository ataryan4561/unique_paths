#include"header.h"
int main()
{
	int n = 3;
	int m = 7;
	int ans = 0;
	unique_paths(&n,&m,&ans);
//	cout<<ans<<"\n";
	printf("%d\n",ans);
	return 0;
}
