ptr pre (ptr h, int x) 
{
    if (h == NULL || h->next == NULL) // 如果链表为空或只有一个结点，返回NULL
    {
        return NULL;
    }

    ptr curr = h;
    ptr next_node = curr->next;
    
    while (next_node != NULL) 
    {
        if (next_node->data == x) // 找到了所查找元素的结点
        {
            return curr; // 返回前驱结点
        }
        curr = next_node;
        next_node = next_node->next;
    }
    return NULL; // 没有找到所查找元素的结点，返回NULL
}