# Trabalho I - Programação Concorrente (2018/1)
### Datas de Apresentação: 02/05 e 04/05
## Enunciado

O Trabalho I do primeiro semestre de 2018 (2018/1) para a disciplina de Programação Concorrente (INE 5410) é um sistema concorrente de funcionamento de um aeroporto. Nesse sistema de aeroporto, existem três recursos principais: i) pistas de pouso e decolagem; ii) portões de embarque e desembarque; e iii) esteiras de malas. Estes recursos do aeroporto são utilizados pelos  aviões.

##Aviões

Aviões são consumidores de recursos do aeroporto e deverão ser representados por threads na sua solução. Basicamente, eles devem realizar a seguinte rotina: 

###Aproximação ao aeroporto.

Primeiramente o avião deverá realizar uma etapa de aproximação, onde aguardará até que uma das pistas de pouso estejam desocupadas.
 
###Pouso.

Quando uma pista estiver desocupada, o avião deverá então pousar.
 
### Acoplagem a um portão.

Após o pouso, o avião deverá se dirigir a um portão de embarque/desembarque.
 
### Transporte de bagagens.

Ao chegar no portão, as bagagens serão removidas do avião e colocadas em uma das esteiras de malas disponíveis no aeroporto. Então, novos passageiros embarcarão no avião e suas bagagens serão transferidas para o avião. O avião deverá liberar o portão de desembarque/embarque quando as malas dos passageiros que estão embarcando tiverem sido colocadas no avião. Para simplificar o problema, considere que todos os passageiros já terão embarcado quando todas as suas malas tiverem sido colocadas no avião.

### Decolagem.

Após o transporte de bagagens o avião deverá novamente escolher uma pista para, então, decolar.
Aviões (threads) deverão ser criados em intervalos de tempo aleatórios (em milissegundos) entre NOVO_AVIAO_MIN e NOVO_AVIAO_MAX. Aviões deverão finalizar sua execuções quando tiverem decolado.

## Pistas de pouso e decolagem

Pistas de decolagem e pouso são recursos que devem ser utilizados pelos aviões. As pistas podem ser usadas por apenas um avião de cada vez.     Quando a pista estiver liberada, o avião poderá realizar o pouso/decolagem. Você deverá considerar que o tempo de utilização para decolagem e pouso são fixos (parâmetro TEMPO_POUSO_DECOLAGEM). A sua solução deverá permitir a escolha do número de pistas do aeroporto (parâmetro NUMERO_PISTAS).

## Portões de embarque e desembarque

Portões de embarque e desembarque também são recursos que devem ser utilizados pelos aviões. Portões só podem ser acessados por aviões que já aterrissaram. Você deverá considerar um tempo fixo para evacuar as bagagens do avião (parâmetro TEMPO_REMOVER_BAGAGENS) e colocá-las na esteira. Da mesma forma, você deverá assumir um tempo fixo para inserir novas bagagens no avião (parâmetro TEMPO_INSERIR_BAGAGENS). As novas bagagens somente poderão ser inseridas após a evacuação das bagagens do avião. Por fim, é importante notar que um avião só pode evacuar suas malas caso haja ao menos uma (1) esteira disponível no sistema. A sua solução deverá permitir a escolha do número de portões de embarque/desembarque do aeroporto (parâmetro NUMERO_PORTOES). 

##Esteiras de malas

Esteiras também são recursos que devem ser utilizados pelos aviões. Esteiras só podem ser acessadas por aviões que já pousaram e acessaram um portão de embarque. Diferentemente dos recursos anteriores, as esteiras poderão ser compartilhadas, podendo receber bagagens de diferentes aviões. O número máximo de aviões que poderão usar uma mesma esteira deverá ser especificado pelo parâmetro MAXIMO_AVIOES_ESTEIRA. Quando colocadas em uma esteira, as bagagens de um avião permanecerão nela por um tempo fixo (parâmetro TEMPO_BAGAGENS_ESTEIRA). Um avião não fica bloqueado enquanto usa a esteira, mas sua requisição deverá ser processada antes da esteira ficar vaga. A sua solução deverá permitir a escolha do número de esteiras do aeroporto (parâmetro NUMERO_ESTEIRAS).
