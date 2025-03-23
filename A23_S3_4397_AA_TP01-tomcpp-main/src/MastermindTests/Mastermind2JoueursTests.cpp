#include "CppUnitTest.h"
#include "../Mastermind/MasterMind2Joueurs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MastermindTests
{
	TEST_CLASS(MasterMind2JoueursTests)
	{
	public:
		TEST_METHOD(nombrePionBienPlace_QuandPropositionVide_ExceptionLevee)
		{
			// Arranger
			Jeu* masterMind2Joueurs = new MasterMind2Joueurs(3,4,2,"rrt");
			const std::string proposition = "";

			// Agir et Auditer
			Assert::ExpectException<std::invalid_argument>([&]() { masterMind2Joueurs->nombrePionBienPlace(proposition); });
		}

		TEST_METHOD(nombrePionBienPlace_QuandPropositionManque_Zero)
		{
			// Arranger
			Jeu* masterMind2Joueurs = new MasterMind2Joueurs(4, 4, 2, "rrt");
			masterMind2Joueurs->propositionModif("rtrt");
			const std::string& proposition = "grt";
			int nombreDePionBienPlaceAttendu = 0;

			// Agir
			int resultatPionBienPlaceCalcule = masterMind2Joueurs->nombrePionBienPlace(proposition);

			// Auditer
			Assert::AreEqual(nombreDePionBienPlaceAttendu, resultatPionBienPlaceCalcule);
		}

		TEST_METHOD(nombrePionBienPlace_QuandPionsBienPlace_Trois)
		{
			// Arranger
			Jeu* masterMind2Joueurs = new MasterMind2Joueurs(3, 4, 2, "abcd");
			masterMind2Joueurs->propositionModif("abc");
			const std::string proposition = "abc";
			int nombreDePionBienPlaceAttendu = 3;

			// Agir
			int resultatPionBienPlaceCalcule = masterMind2Joueurs->nombrePionBienPlace(proposition);

			// Auditer
			Assert::AreEqual(nombreDePionBienPlaceAttendu, resultatPionBienPlaceCalcule);
		}

		TEST_METHOD(nombrePionBienPlace_QuandAucunPionsBienPlace_Zero)
		{
			// Arranger
			Jeu* masterMind2Joueurs = new MasterMind2Joueurs(3, 4, 2, "abcd");
			masterMind2Joueurs->propositionModif("abc");
			const std::string proposition = "def";
			int nombreDePionBienPlaceAttendu = 0;

			// Agir
			int resultatPionBienPlaceCalcule = masterMind2Joueurs->nombrePionBienPlace(proposition);

			// Auditer
			Assert::AreEqual(nombreDePionBienPlaceAttendu, resultatPionBienPlaceCalcule);
		}
		TEST_METHOD(nombrePionBienPlace_QuandPlusieursPionsBienPlaces_Quatre)
		{
			// Arranger
			Jeu* masterMind2Joueurs = new MasterMind2Joueurs(4, 4, 2, "abcd");
			masterMind2Joueurs->propositionModif("aBcD");
			const std::string proposition = "aBcD";
			int nombreDePionBienPlaceAttendu = 4; // Tous les pions sont bien placés, la casse est ignorée.

			// Agir
			int resultatPionBienPlaceCalcule = masterMind2Joueurs->nombrePionBienPlace(proposition);

			// Auditer
			Assert::AreEqual(nombreDePionBienPlaceAttendu, resultatPionBienPlaceCalcule);
		}

		TEST_METHOD(nombrePionBienPlace_QuandPlusLongueProposition_Trois)
		{
			// Arranger
			Jeu* masterMind2Joueurs = new MasterMind2Joueurs(3, 4, 2, "abc");
			masterMind2Joueurs->propositionModif("abcd");
			const std::string proposition = "abcd";
			int nombreDePionBienPlaceAttendu = 3;

			// Agir
			int resultatPionBienPlaceCalcule = masterMind2Joueurs->nombrePionBienPlace(proposition);

			// Auditer
			Assert::AreEqual(nombreDePionBienPlaceAttendu, resultatPionBienPlaceCalcule);
		}
	};
}
