# TESTES UNITÁRIOS PARA LIBFT

Esse é um repositório de testes unitários para facilitar a vida de quem está avaliando o primeiro projeto da formação da 42, o libft. Estamos utilizando o Unity para realizar os testes unitários, leia abaixo para entender como você pode rodar os testes com o seu código.

Esse repositório não foi feito para ser utilizado como um tipo de trapaça, apenas para estudar testes unitários e facilitar a vida de quem está avaliando a libft e não ter que ficar descomentando main que nem louco.

## Como Rodar

- **Clone o repositório:**
```bash
git clone https://github.com/FelBenini/Testes-Unitarios-para-Libft.git libft_tests
```
- **Copie a pasta da sua libft para a pasta src na raiz do repositório:**
```bash
cd ./libft_tests
cp -r /caminho/para/sua/libft ./src
```
- **Rode os testes com o Makefile:**
```bash
make test
```

-- **Para rodar com os exercícios Bonus:**
```bash
make test-bonus
```

-- **Para checar os nomes dos arquivos:**
```bash
make file
```

-- **Para checar os nomes dos arquivos Bonus:**
```bash
make file-bonus
```

## Testes Prontos

- [x] Funções da Libc (parte 1)
- [ ] Funções Adicionais (parte 2)
- [ ] Funções Bônus

