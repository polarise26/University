import ttg

print("This is Karan Taneja's code. SAP - 500084399.")

conj = ttg.Truths(['P', 'Q'], ['P and Q'])
print(f'Table #1 Conjunction:\n{conj}')

disj = ttg.Truths(['P', 'Q'], ['P or Q'])
print(f'\nTable #2 Disjunction:\n{disj}')

neg = ttg.Truths(['P'], ['not P'])
print(f'\nTable #3 Negation:\n{neg}')

impl = ttg.Truths(['P', 'Q'], ['P implies Q'])
print(f'\nTable #4 Implication:\n{impl}')

bicon = ttg.Truths(['P', 'Q'], ['(P implies Q) and (Q implies P)'])
print(f'\nTable #5 Bi conditional:\n{bicon}')

demorgan = ttg.Truths(['P', 'Q'], ['not P and not Q', 'not(P or Q)'])
print(f"\nTable #6:\nProve deMorgans Law: (A and B)' == A' or B'\n{demorgan}")
