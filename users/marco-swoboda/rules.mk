COMBO_ENABLE = yes


SRC += marco-swoboda.c \
		process_records.c


ifdef COMBO_ENABLE
    SRC += combos.c
endif
