void creat(BiTree &Tree) {
    char ch;
    scanf(" %c", &ch); // 读取字符，注意前面有个空格用来过滤掉空白符
    if (ch == '#') {
        Tree = NULL; // 如果当前字符为'#'，则当前子树为空，即无左子或右子
    } else {
        Tree = (BiTree)malloc(len); // 分配内存
        Tree->data = ch; // 将读取的字符赋值给节点的数据域
        creat(Tree->lchild); // 递归构造左子树
        creat(Tree->rchild); // 递归构造右子树
    }
}

int Depth(BiTree Tree) {
    if (Tree == NULL) {
        return 0; // 空树的高度为0
    } else {
        int leftDepth = Depth(Tree->lchild); // 计算左子树的高度
        int rightDepth = Depth(Tree->rchild); // 计算右子树的高度
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1; // 返回较大的高度加1
    }
}