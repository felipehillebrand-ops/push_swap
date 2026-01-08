
import random
import subprocess
import sys

def sa(stack_a, stack_b):
    if len(stack_a) > 1:
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]

def sb(stack_a, stack_b):
    if len(stack_b) > 1:
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]

def ss(stack_a, stack_b):
    sa(stack_a, stack_b)
    sb(stack_a, stack_b)

def pa(stack_a, stack_b):
    if stack_b:
        stack_a.insert(0, stack_b.pop(0))

def pb(stack_a, stack_b):
    if stack_a:
        stack_b.insert(0, stack_a.pop(0))

def ra(stack_a, stack_b):
    if len(stack_a) > 1:
        stack_a.append(stack_a.pop(0))

def rb(stack_a, stack_b):
    if len(stack_b) > 1:
        stack_b.append(stack_b.pop(0))

def rr(stack_a, stack_b):
    ra(stack_a, stack_b)
    rb(stack_a, stack_b)

def rra(stack_a, stack_b):
    if len(stack_a) > 1:
        stack_a.insert(0, stack_a.pop())

def rrb(stack_a, stack_b):
    if len(stack_b) > 1:
        stack_b.insert(0, stack_b.pop())

def rrr(stack_a, stack_b):
    rra(stack_a, stack_b)
    rrb(stack_a, stack_b)

OPERATIONS = {
    "sa": sa, "sb": sb, "ss": ss,
    "pa": pa, "pb": pb,
    "ra": ra, "rb": rb, "rr": rr,
    "rra": rra, "rrb": rrb, "rrr": rrr
}

def is_sorted(stack):
    return all(stack[i] <= stack[i + 1] for i in range(len(stack) - 1))

def main():
    # 1. Generate 4 unique random integers
    try:
        numbers = random.sample(range(-2147483648, 2147483647), 4)
    except OverflowError:
        # Fallback for environments with smaller integer limits
        numbers = random.sample(range(-1000, 1000), 4)

    print(f"Números aleatórios gerados: {' '.join(map(str, numbers))}")

    # 2. Execute push_swap
    args = [str(n) for n in numbers]
    try:
        result = subprocess.run(['./push_swap'] + args, capture_output=True, text=True, check=True)
        operations = result.stdout.strip().split('\n')
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        print(f"Erro ao executar o ./push_swap: {e}")
        sys.exit(1)

    print(f"Operações recebidas: {operations}")

    # 3. Simulate operations
    stack_a = list(numbers)
    stack_b = []

    for op in operations:
        if op in OPERATIONS:
            OPERATIONS[op](stack_a, stack_b)
        elif op:
            print(f"Operação desconhecida: '{op}'")

    # 4. Verify the result
    print(f"Estado final da pilha A: {stack_a}")
    print(f"Estado final da pilha B: {stack_b}")

    if is_sorted(stack_a) and not stack_b:
        print("\\n✅ Sucesso! A pilha A está ordenada e a pilha B está vazia.")
    else:
        print("\\n❌ Falha! A ordenação não foi concluída corretamente.")
        sys.exit(1)

if __name__ == "__main__":
    main()
