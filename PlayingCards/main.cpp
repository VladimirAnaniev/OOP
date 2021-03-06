#include <iostream>

using namespace std;

enum CardValue {
    two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

const char *getValueAsString(CardValue val) {
    switch (val) {
        case two:
            return "2";
        case three:
            return "3";
        case four:
            return "4";
        case five:
            return "5";
        case six:
            return "6";
        case seven:
            return "7";
        case eight:
            return "8";
        case nine:
            return "9";
        case ten:
            return "10";
        case jack:
            return "J";
        case queen:
            return "Q";
        case king:
            return "K";
        case ace:
            return "A";
        default:
            return "";
    }
}

enum CardColor {
    club, diamond, heart, spade
};

const char *getColorAsString(CardColor color) {
    switch (color) {
        case club:
            return "\u2663";
        case diamond:
            return "\u2666";
        case heart:
            return "\u2665";
        case spade:
            return "\u2660";
        default:
            return "";
    }
}

class Card {
    CardColor color;
    CardValue value;

public:
    Card(CardColor color = spade, CardValue value = ace) {
        this->setColor(color);
        this->setValue(value);
    }

    void setColor(CardColor c) { this->color = c; }

    void setValue(CardValue v) { this->value = v; }

    CardColor getColor() { return this->color; }

    CardValue getValue() { return this->value; }

    void print() {
        cout << getValueAsString(this->getValue()) << getColorAsString(this->getColor()) << endl;
    }

    bool isEqual(Card &card) {
        return this->getColor() == card.getColor() && this->getValue() == card.getValue();
    }
};


class Deck {
    Card cards[52];

public:
    Deck() {
        int i = 0;
        for (int color = 0; color < 4; color++) {
            for (int power = 0; power < 13; power++) {
                this->cards[i++] = Card((CardColor) color, (CardValue) power);
            }
        }
    }

    Card getTopCard() { return this->cards[51]; }

    Card getBottomCard() { return this->cards[0]; }

    void shuffleCard(int index) {
        int random = rand() % 52;

        Card that = this->cards[index];
        this->cards[index] = this->cards[random];
        this->cards[random] = that;
    }

    void shuffleDeck() {
        for (int i = 0; i < 52; i++) {
            this->shuffleCard(i);
        }
    }
};

int main() {
    Card c;
    Card c2(club, two);

    c.print();
    c2.print();

    cout << c.isEqual(c2) << endl;

    return 0;
}