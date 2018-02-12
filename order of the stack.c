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

void InitStack(Stack *stack)//�����ջstack
{
	stack->base = (int*)malloc(sizeof(int)*STACK_INIT_SIZE);
	if (!stack->base){
		printf("error!!\n");
		return;
	}
	stack->top = stack->base;
	stack->StackSize = STACK_INIT_SIZE;
}

int IsEmpty(Stack *stack)//�ж�ջ�ǲ��ǿ�ջ
{
	if (stack->base == stack->top)
		return 1;
	return 0;
}
int IsFull(Stack *stack)//�ж�ջstack�ǲ�������
{
	if (stack->top - stack->base == stack->StackSize)
		return 1;
	return 0;
}

void GetTop(Stack *stack, int *data)//��ȡջ��Ԫ��
{
	if (stack->base == stack->top)
		return;
	stack->top--;
	*data = *stack->top;
	stack->top++;
}

void Stack_Push(Stack *stack, int data)//��ջ
{
	if (stack->top - stack->base == stack->StackSize)//��ջ�ж�ջ��
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

void Stack_Pop(Stack *stack, int *data)//��ջ
{
	if (stack->base == stack->top)//��ջ�ж�ջ�Ƿ�Ϊ��
		return;
	stack->top--;
	*data = *stack->top;//ջ��ʼ��ָ��ջ��Ԫ�ص���һ��λ��
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
		Stack_Push(&stack, i + 1);//���ν�1-10����ջ
	}
	printf("ջ�ĳ���Ϊ: %d", Stack_Size(&stack));
	GetTop(&stack, &data);
	printf("\nջ��Ԫ��Ϊ: %d", data);
	printf("\nջ�Ƿ�����: %d", IsFull(&stack));
	printf("\n����Ԫ�س�ջ\n");
	for (i = 0; i < 10; i++){
		Stack_Pop(&stack, &data);
		printf("%d ", data);
	}
	printf("\nջ�Ƿ�Ϊ��: %d\n", IsEmpty(&stack));
	system("pause");
	return 0;
}