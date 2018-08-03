#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>

using namespace eosio;
using std::string;

class eosbay : public contract
{

  public:
    eosbay(account_name self) : contract(self) {}

    // @abi action
    void addlisting(const account_name  _seller,
                    const account_name  _account_for_sale,
                    //const uint64_t      _listing_type,
                    const asset         _price);

    // @abi action
    void dellisting (const uint64_t _listing_id);

    // @abi action
    void updatelistin (const uint64_t _listing_id,
                       const asset      _price);

    // @abi action
    void addbid(const account_name  _bidder,
                const uint64_t      _listing_id,
                const asset         _bid_amount);

    // @abi action
    void updatebid (const uint64_t  _bid_id,
                    const asset     _new_bid_amount);
    
    // @abi action
    void deletebid (const uint64_t _bid_id);

    // @abi action
    void purchase (const uint64_t       _listing_id,
                   const account_name   _buyer);

    // @abi action
    void changekey(const account_name   _account,
                   const string         _newkey);

  private:

    // @abi table listings i64
    struct listing
    {
        uint64_t        listing_id;
        account_name    seller;
        account_name    account_for_sale;
        //uint8_t         listing_type;
        asset           price;
        uint32_t        created_date;

        uint64_t primary_key() const { return listing_id; }
        EOSLIB_SERIALIZE (listing, (listing_id)(seller)(account_for_sale)(price));
    };

    typedef eosio::multi_index<N(listings), listing> listing_table;

    // @abi table bids i64
    struct bid
    {
        uint64_t        bid_id;
        uint64_t        listing_id;
        account_name    bidder;
        asset           bid_amount;
        uint32_t        created_date;
        uint32_t        updated_date;

        uint64_t    primary_key() const { return bid_id; }
        EOSLIB_SERIALIZE(bid, (bid_id)(listing_id)(bidder)(bid_amount));
    };

    typedef eosio::multi_index<N(bids), bid> bid_table;

    const uint8_t   AUCTION = 1;
    const uint8_t   OUTRIGHT_SALE = 2;
};

EOSIO_ABI(eosbay, (addlisting)(dellisting)(addbid)(updatebid)(deletebid)(purchase)(changekey));