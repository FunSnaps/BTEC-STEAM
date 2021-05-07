#pragma once

#include <string>

class Game
{
	public:
		Game(const int& id, const std::string& name, const std::string& desc, const int& cost, const int& agerating, const int& rating, const int& likes, const int& dislikes);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		void setRating();
		int GetRating();
		void addLike();
		void addDislikes();
		const int& GetAgeRating() const;
		const int& GetLikes() const;
		const int& GetDislikes() const;
		const int& GetID() const;
		
	private:
		std::string name;
		std::string description;
		int id, cost, ageRating, rating = 0, likes = 0, dislikes = 0;
		
};