CC='gcc'

default_builder: 
	@echo "The best way is to use 2 pty or redirect output of each proc"
	@echo "USE make soc TO RUN SOCKETS"
	@echo "USE make fifo TO RUN FIFO"
	@echo "USE make mq TO RUN Message Queues"
	@echo "USE make runall to RUN ALL"
	@echo I WILL NOW RUN ALL OF THEM
	@sleep 3
	@make runall

runall: 
	@echo "RUNNING SOCKETS ------------------------------------"
	@sleep 2
	@make soc
	@echo "RUNNING FIFO ---------------------------------------"
	@sleep 2
	@make fifo
	@echo "RUNNING MQ -----------------------------------------"
	@sleep 2
	@make mq
	@echo cleaning
	@make clean

mq: P1mq P2mq
	@echo "running P1mq followed by P2mq"
	@./P1mq &
	@sleep 0.01
	@./P2mq

fifo: P1fifo P2fifo
	@echo "running  P1fifo followed by P2fifo"
	@./P1fifo &
	@sleep 0.01
	@./P2fifo
	
soc: P1soc P2soc
	@echo "running  P1soc followed by P2soc"
	@./P1soc &
	@sleep 0.01
	@./P2soc
	
P1fifo: P1fifo.c
	@$(CC) P1fifo.c -o P1fifo
	
P2fifo: P2fifo.c
	@$(CC) P2fifo.c -o P2fifo
	
P1soc: P1soc.c
	@$(CC) P1soc.c -o P1soc
	
P2soc: P2soc.c
	@$(CC) P2soc.c -o P2soc
	
P1mq: P1mq.c
	@$(CC) P1mq.c -o P1mq -lrt
	
P2mq: P2mq.c
	@$(CC) P2mq.c -o P2mq -lrt

clean:
	@rm -f P1fifo P2fifo P1soc P2soc P1mq P2mq