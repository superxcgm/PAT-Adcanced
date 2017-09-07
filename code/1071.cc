#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>

using namespace std;
char buf [1048580];
map<string, int> mp;

int isalnum(char ch)
{
    if(ch >= '0' && ch <= '9')
        return ch;
    if(ch >= 'A' && ch <= 'Z')
        return ch + ('a' - 'A');
    if(ch >= 'a' && ch <= 'z')
        return ch;
    return -1;
}
int main()
{
    int i = 0, st, en;
    int max_time = -1;
    int len, ch;
    
    //freopen("1071.txt", "r", stdin);
    while(1){
        ch = getchar();
        buf[i++] = ch;
        if(ch == '\n')
            break;
    }
    buf[i] = '\0';
    st = en = 0;
    len = strlen(buf);
    while(en < len){
        if((buf[en] = isalnum(buf[en]))  != -1){
            ++en;
            continue;
        }
        if(st < en){
            string str(buf + st, buf + en);
            ++mp[str];
            if(mp[str] > max_time)
                max_time = mp[str];
        }
        st = en + 1;
        ++en;
    }
    map<string, int>::iterator it = mp.begin();
    for(; it != mp.end(); ++it)
        if(it->second == max_time){
            printf("%s %d", it->first.c_str(), it->second);
            break;
        }
    //while(1);
    return 0;
}