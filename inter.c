#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int id;
    int post[100];
    int friends[100];
    struct node *left, *right;
};
struct node *search1(struct node **list, int x)
{
    struct node *p, *q;
    q = NULL;
    p = (*list);
    while (p != NULL && p->id != x)
    {
        q = p;
        if (x < p->id)
        {
            p = p->left;
        }
        else if (x > p->id)
        {
            p = p->right;
        }
    }
    return p;
}
int nfnd(int a[100], int x)
{
    int i = 0;
    int n = 0;
    while (i < 100 && n != 0)
    {
        if (a[i] == x)
        {
            n = 1;
        }
        i++;
    }
    return n;
}
void vfrnd(struct node **list, int x)
{
    struct node *pres;
    int i = 0;
    pres = search1(list, x);
    if (pres == NULL)
    {
        printf("No such friends present in ur list\n");
    }
    else
    {
        for (i = 0; pres->friends[i] != -1 && i < 100; i++)
        {
            printf("%d\t", pres->friends[i]);
        }
        printf("\n");
    }
}
void view(struct node *list)
{
    if (list != NULL)
    {
        view(list->left);
        printf("%d\t", list->id);
        view(list->right);
    }
    printf("\n");
}
void refine(struct node *user, struct node *list, int n)
{
    if ((list) != NULL)
    {
        refine(user, (list)->left, n);
        if (!nfnd(user->friends, (list)->id))
        {
            user->friends[n] = (list)->id;
        }
    }
}

void delete (struct node **t, int key)
{
    struct node *temp, *prev, *p, *q, *cur;
    prev = NULL;
    if ((*t) == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        cur = search1(t, key);
        if (cur == NULL)
        {
            printf("Node not found\n");
        }
        else
        {
        }
    }
}
void add(struct node **list, int x, int frnd[100], int n, int *post)
{
    struct node *temp, *pres, *prev;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->id = x;
    for (int i = 0; i < 100; i++)
    {
        temp->friends[i] = frnd[i];
    }
    for (int i = 0; i < 100; i++)
    {
        temp->post[i] = post[i];
    }
    temp->left = temp->right = NULL;
    pres = (*list);
    prev = NULL;
    if (pres == NULL)
    {
        (*list) = temp;
    }
    else
    {
        while (pres != NULL)
        {
            prev = pres;
            if (x < pres->id)
                pres = pres->left;
            else
                pres = pres->left;
        }
        if (x < prev->id)
        {
            prev->left = temp;
        }
        else
        {
            prev->right = temp;
        }
    }
    refine(temp, *list, n);
}
void vpost(struct node **list, int x)
{
    struct node *pres;
    int i = 0;
    pres = search1(list, x);
    if (pres == NULL)
    {
        printf("No such friends present in ur list\n");
    }
    else
    {
        for (i = 0; pres->post[i] != -1 && i < 100; i++)
        {
            printf("%d\t", pres->post[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct node *list;
    list = NULL;
    int x, ch, n, sz;
    int frnd[100], post[100];
    do
    {
        printf("\n1)Add friend list\n2)Remove a friend\n3)View friends of your list\n4)View friend list of your friend\n5)View posts of your friends\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (int i = 0; i < 100; i++)
            {
                frnd[i] = -1;
                post[i] = -1;
            }
            printf("Enter user id, no. of his/her friends and no. of his posts respectively\n");
            scanf("%d %d %d", &x, &n, &sz);
            printf("Enter the ids of his/her friends\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &frnd[i]);
            }
            printf("Enter the ids of his posts\n");
            for (int i = 0; i < sz; i++)
            {
                scanf("%d", &post[i]);
                printf("hello\n");
            }
            add(&list, x, frnd, n, post);
            break;
        case 2:
            printf("Enter user id of friend you want to delete from your circle\n");
            scanf("%d", &x);
            delete (&list, x);
            break;
        case 3:
            view(list);
            break;
        case 4:
            printf("Enter id of one of your friend : ");
            scanf("%d", &x);
            vfrnd(&list, x);
            break;
        case 5:
            printf("Enter your friend id : ");
            scanf("%d", &x);
            vpost(&list, x);
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}