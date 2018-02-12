#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{
	int *base;
	int *top;
	int StackSize;
}Stack;

void InitStack(Stack *stack)//构造空栈stack
{
	stack->base = (int*)malloc(sizeof(int)*STACK_INIT_SIZE);
	if (!stack->base){
		printf("error!!\n");
		return;
	}
	stack->top = stack->base;
	stack->StackSize = STACK_INIT_SIZE;
}

int IsEmpty(Stack *stack)//判断栈是不是空栈
{
	if (stack->base == stack->top)
		return 1;
	return 0;
}
int IsFull(Stack *stack)//判断栈stack是不是满了
{
	if (stack->top - stack->base == stack->StackSize)
		return 1;
	return 0;
}

void GetTop(Stack *stack, int *data)//获取栈顶元素
{
	if (stack->base == stack->top)
		return;
	stack->top--;
	*data = *stack->top;
	stack->top++;
}

void Stack_Push(Stack *stack, int data)//入栈
{
	if (stack->top - stack->base == stack->StackSize)//入栈判断栈满
	{
		stack->base = (int*)realloc(stack->base, sizeof(int)*(stack->StackSize + STACKINCREMENT));
		if (!stack->base)
			return;
		stack->top = stack->base + stack->StackSize;
		stack->StackSize = stack->StackSize + STACKINCREMENT;
	}
	*stack->top = data;
	stack->top++;
}

void Stack_Pop(Stack *stack, int *data)//出栈
{
	if (stack->base == stack->top)//出栈判断栈是否为空
		return;
	stack->top--;
	*data = *stack->top;//栈顶始终指向栈定元素的下一个位置
}

int Stack_Size(Stack *stack)
{
	return (stack->top - stack->base);
}

int main()
{
	int i, data;
	Stack stack;
	InitStack(&stack);
	for (i = 0; i < 10; i++){
		Stack_Push(&stack, i + 1);//依次将1-10推入栈
	}
	printf("栈的长度为: %d", Stack_Size(&stack));
	GetTop(&stack, &data);
	printf("\n栈顶元素为: %d", data);
	printf("\n栈是否满了: %d", IsFull(&stack));
	printf("\n所有元素出栈\n");
	for (i = 0; i < 10; i++){
		Stack_Pop(&stack, &data);
		printf("%d ", data);
	}
	printf("\n栈是否为空: %d\n", IsEmpty(&stack));
	system("pause");
	return 0;
}