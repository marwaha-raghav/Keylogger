#include <stdio.h>
#include <windows.h>

void ClearBrowserCache();
void ClearMozillaCache();
void ClearChromeCache();
void ClearOperaCache();



void ClearMozillaCache()
{
    char path[256] = "C:\\Users\\";
    char cachePath[256] = "\\AppData\\Local\\Mozilla\\Firefox\\Profiles\\gv3rw9bw.default-release\\cache2";
    char removepath[256] = "";
    strcat(path,getenv("USERNAME"));
    strcat(path, cachePath);
    strcat(removepath,"rmdir /Q /S ");
    strcat(removepath, path);
    printf("path: %s\n remove path: %s\n",path,removepath);

}

void ClearBrowserCache()
{
    ClearMozillaCache();

}

int main()
{
    ClearMozillaCache();
    return 0;
}