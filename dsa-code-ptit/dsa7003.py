def is_operand(x):
    return x == '+' or x == '-' or x == '*' or x == '/'

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        st = []
        operands = '+-*/'
        check = False
        for x in s:
            if x != ')':
                st.append(x)
            else:
                has_o = False
                top = st.pop()
                while st and top != '(':
                    if top in operands:
                        has_o = True
                    top = st.pop()
                if has_o == False:
                    check = True
                    break
        print('Yes' if check else 'No')
        