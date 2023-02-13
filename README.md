# Problema do Metrô de Paris

Suponha que queremos construir um sistema para auxiliar um usuário do metrô de Paris a saber o trajeto mais rápido entre a estação onde ele se encontra e a estação de destino. O usuário tem um painel com o mapa, podendo selecionar a sua estação de destino. O sistema então acende as luzes sobre o mapa mostrando o melhor trajeto a seguir (em termos de quais estações ele vai atravessar., e quais as conexões mais rápidas a fazer – se for o caso).

Condições:
* A distância em linha reta entre duas estações quaisquer é dada em uma tabela. Para facilitar a vida, considere apenas 4 linhas do metrô.
* A velocidade média de um trem é de 30km/h;
* Tempo gasto para trocar de linha dentro de mesma estação (fazer baldeação) é de
4 minutos.

##### Problema resolvido usando Busca heurística com A*.
