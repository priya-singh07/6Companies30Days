// Delete N nodes after M nodes of a linked list 


class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        while(head)
        {
            int c=1;
            while(head!=NULL && c<M)
            {
                head=head->next;
                c++;
            }
            int d=0;
            Node* prev=head;
            while(head!=NULL && d<N)
            {
                head=head->next;
                d++;
            }
            if(prev)
            {
                if(head)
                head=head->next;
                else
                head=NULL;
                prev->next=head;
            }
        }
    }
};