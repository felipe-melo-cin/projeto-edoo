#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

class StateMachine { // CONTROLA OS ESTADOS DO JOGO

    private:

        StateMachine(); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO

        // ESTADOS DO JOGO
        bool emJogo;
        bool venceu;

    public:

        // SINGLETON DESIGN PATTERN

        StateMachine(const StateMachine&) = delete;
        StateMachine& operator=(const StateMachine&) = delete;

        static StateMachine& getInstance();

        // END SINGLETON DESIGN PATTERN

        // RETORNA ESTADO DO JOGO
        bool getEmJogo() const { return emJogo; }
        bool getVenceu() const { return venceu; }

        // INVERTE ESTADO DO JOGO
        void toggleEmJogo() { emJogo = !emJogo; }
        void toggleVenceu() { venceu = !venceu; }

};

#endif