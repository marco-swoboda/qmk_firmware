COMBO_ENABLE = yes


SRC += marco-swoboda.c \
		process_records.c

ifdef COMBO_ENABLE
    SRC += combos.c
endif

ifdef ENCODER_ENABLE
	SRC += encoder.c
endif
