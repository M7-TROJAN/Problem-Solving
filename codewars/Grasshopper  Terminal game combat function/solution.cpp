int combat(int health, int damage)
{

    int newHealth = health - damage;

    return newHealth > 0 ? newHealth : 0;
}

// .........................................................

int combat(int health, int damage)
{
    return damage > health ? 0 : health - damage;
}