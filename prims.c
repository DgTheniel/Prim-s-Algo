#include <stdio.h>
int inf = 1000000007;

int main()
{
    int n;
    printf("Enter the no of vertices in graph : ");
    scanf("%d",&n);
    int graph[n+1][n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            graph[i][j] = -1;
        }
    }
    int m;
    printf("Enter the of edges in graph : ");
    scanf("%d",&m);
    printf("Enter vertex1 , vertex2 and weight in moving between vertex1 and vertex2 : \n");
    for(int i = 0 ; i < m ; i++)
    {
        int u , v , w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else if(graph[i][j] == -1)
                graph[i][j] = inf;
        }
    }

    // PRIM'S ALGORITHM :
    int t[n][2] , p[n+1] , d[n+1] , s[n+1];
    int mn = inf;
    int src = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(graph[i][j] != 0 && graph[i][j] <= mn)
            {
                mn = graph[i][j];
                src = i;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        d[i] = graph[src][i];
        s[i] = 0;
        p[i] = src;
    }
    s[src] = 1;
    int sum = 0 , k = 0;
    for(int i = 2 ; i <= n ; i++)
    {
        int u = -1;
        mn = inf;
        for(int j = 1 ; j <= n ; j++)
        {
            if(s[j] == 0)
            {
                if(d[j] <= mn)
                {
                    mn = d[j];
                    u = j;
                }
            }
        }
        t[k][0] = u;
        t[k][1] = p[u];
        k++;
        sum += graph[u][p[u]];
        s[u] = 1;
        for(int v = 1 ; v <= n ; v++)
        {
            if(s[v] == 0 && graph[u][v] < d[v])
            {
                d[v] = graph[u][v];
                p[v] = u;
            }
        }
    }
    if(sum >= inf)
        printf("The minimum spanning tree doesn't exists.");
    else
    {
        printf("Spanning tree exists and minimum spanning tree is : \n");
        for(int i = 0 ; i < n-1 ; i++)
        {
            printf("%d %d\n",t[i][0],t[i][1]);
        }
        printf("The total cost of minimum spanning tree is %d.\n",sum);
    }
    return 0;
}