#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coef;
    int xexp, yexp, zexp;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    return temp;
}

NODE attach(int coef, int x, int y, int z, NODE head)
{
    NODE temp = getnode(), cur = head;
    temp->coef = coef;
    temp->xexp = x;
    temp->yexp = y;
    temp->zexp = z;

    while(cur->link != head)
        cur = cur->link;

    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read_poly(NODE head)
{
    int n, i, coef, x, y, z;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Coefficient: ");
        scanf("%d", &coef);
        printf("Enter powers of x y z: ");
        scanf("%d %d %d", &x, &y, &z);
        head = attach(coef, x, y, z, head);
    }
    return head;
}

void display(NODE head)
{
    NODE temp = head->link;
    if(temp == head)
    {
        printf("Polynomial is empty\n");
        return;
    }

    while(temp != head)
    {
        printf("%dx^%dy^%dz^%d", temp->coef,temp->xexp, temp->yexp, temp->zexp);
        temp = temp->link;
        if(temp != head)
            printf(" + ");
    }
    printf("\n");
}

int poly_evaluate(NODE head)
{
    int x, y, z, sum = 0;
    NODE temp = head->link;

    printf("\nEnter x y z values: ");
    scanf("%d %d %d", &x, &y, &z);

    while(temp != head)
    {
        sum += temp->coef *pow(x, temp->xexp) *pow(y, temp->yexp) *pow(z, temp->zexp);
        temp = temp->link;
    }
    return sum;
}

NODE poly_sum(NODE h1, NODE h2, NODE h3)
{
    NODE a = h1->link, b = h2->link;

    while(a != h1 && b != h2)
    {
        if(a->xexp == b->xexp && a->yexp == b->yexp && a->zexp == b->zexp)
        {
            h3 = attach(a->coef + b->coef,a->xexp, a->yexp, a->zexp, h3);
            a = a->link;
            b = b->link;
        }
        else if(a->xexp > b->xexp)
        {
            h3 = attach(a->coef, a->xexp, a->yexp, a->zexp, h3);
            a = a->link;
        }
        else
        {
            h3 = attach(b->coef, b->xexp, b->yexp, b->zexp, h3);
            b = b->link;
        }
    }

    while(a != h1)
    {
        h3 = attach(a->coef, a->xexp, a->yexp, a->zexp, h3);
        a = a->link;
    }

    while(b != h2)
    {
        h3 = attach(b->coef, b->xexp, b->yexp, b->zexp, h3);
        b = b->link;
    }
    return h3;
}
int main()
{
    NODE head = getnode(), head1 = getnode();
    NODE head2 = getnode(), head3 = getnode();
    int ch, res;

    head->link = head;
    head1->link = head1;
    head2->link = head2;
    head3->link = head3;

    while(1)
    {
        printf("\n--- MENU ---\n1. Polynomial Evaluation\n2. Polynomial Addition\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                head = read_poly(head);
                display(head);
                res = poly_evaluate(head);
                printf("Result = %d\n", res);
                break;
            case 2:
                printf("\nEnter POLY1\n");
                head1 = read_poly(head1);
                display(head1);
                printf("\nEnter POLY2\n");
                head2 = read_poly(head2);
                display(head2);
                head3 = poly_sum(head1, head2, head3);
                printf("\nPOLY SUM:\n");
                display(head3);
                break;
            case 3:
                exit(0);
        }
    }
}
