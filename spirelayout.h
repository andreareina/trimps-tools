#ifndef SPIRELAYOUT_H_
#define SPIRELAYOUT_H_

#include <cstdint>
#include <random>

struct TrapUpgrades
{
	uint16_t fire;
	uint16_t frost;
	uint16_t poison;
	uint16_t lightning;

	TrapUpgrades();
};

struct TrapEffects
{
	unsigned fire_damage;
	unsigned frost_damage;
	unsigned chill_dur;
	unsigned poison_damage;
	unsigned lightning_damage;
	unsigned shock_dur;
	unsigned damage_multi;
	unsigned special_multi;

	TrapEffects(const TrapUpgrades &);
};

struct Layout
{
	typedef std::minstd_rand Random;

	TrapUpgrades upgrades;
	std::string data;
	std::uint64_t damage;
	std::uint64_t cost;
	unsigned cycle;

	static const char traps[];

	Layout();

	std::uint64_t update_damage();
	std::uint64_t simulate(uint64_t, bool = false) const;
	std::uint64_t update_cost();
	void cross_from(const Layout &, Random &);
	void mutate(unsigned, unsigned, Random &);
	bool is_valid() const;
};

#endif
