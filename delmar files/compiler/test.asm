        READ    x
        L0:NOOP
        LOAD    x
        STORE   T0
        LOAD    5
        SUB     T0
        BRZNEG   L1
        LOAD    x
        STORE   TOUT
        WRITE   TOUT
        LOAD    x
        STORE   T1
        LOAD    1
        ADD     T1
        STORE   x
        BR L0
                L1:NOOP
STOP
         TOUT 0
         x 1
         T0 0
         T1 0
