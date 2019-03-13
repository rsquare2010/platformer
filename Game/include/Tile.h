#ifndef TILE_H
#define TILE_H


// This is a quick and dirty implementation of a TileMap
class TileMap{
public:
    
    // Creates a new tile map.
    // rows and cols are how many differnt tiles they are
    // _TileWidth and _TileHeight are the size of each individual
    // tile. Typically this works best if they are square
    // for this implementation.
    // _mapX, and _mapY are the size of the tilemap.
    TileMap(std::string tileSheetFileName, int rows, int cols, int _TileWidth, int _TileHeight, int _mapX, int _mapY, SDL_Renderer* ren){
        // Setup variables
        m_Rows = rows;
        m_Cols = cols;
        m_TileWidth = _TileWidth;
        m_TileHeight = _TileHeight;
        m_MapX = _mapX;
        m_MapY = _mapY;
        // Load the TileMap Image
        // This is the image that will get
        // sliced into smaller subsections of individual tiles.
        m_TileSpriteSheet = SDL_LoadBMP(tileSheetFileName.c_str());
        if(m_TileSpriteSheet==NULL){
               SDL_Log("Failed to allocate surface");
        }else{
            // Create a texture from our surface
            // Textures run faster and take advantage of
            //  hardware acceleration
            m_Texture = SDL_CreateTextureFromSurface(ren, m_TileSpriteSheet);
        }

        // Setup the TileMap array
        // This sets each tile to '0'
        m_Tiles = new int[m_MapX*m_MapY];
        for(int i=0; i < m_MapX*m_MapY; i++){
            m_Tiles[i] = -1; // Default value is no tile.
        }

        // Generate a random/default map
//        generateRandomMap();
    }

    // TileMap Destructor
    ~TileMap(){
        // Free our surfaces
        SDL_FreeSurface(m_TileSpriteSheet);
        m_TileSpriteSheet=NULL;
        SDL_DestroyTexture(m_Texture);
        // Remove our TileMap
        delete[] m_Tiles;
    }

    // Helper function to generate a random map
    void generateRandomMap(){
        for(int i= 0; i < m_MapY; i++){
            for(int j= 0; j < m_MapX; j++){
                if(i==m_MapY-1){
                    std::cout<<"x: "<<i<<" y: "<<j<<std::endl;
                    setTile(i,j,1);
                }
           }
        }
        setTile(3,3,1);
        setTile(2,2,0);
        setTile(4,4,2);
        setTile(5,5,3);
        setTile(5,6,0);
    }
    
    // Sets a tile a certain type
    void setTile(int x, int y, int type){
        m_Tiles[x * m_MapY + y] = type;
    }


    // Returns what the tile is at a specific position.
    int getTileType(int x, int y){
        return m_Tiles[x * m_MapY + y];
    }

    // render TileMap
    void render(SDL_Renderer* ren){
        SDL_Rect Src, Dest;
        for(int i= 0; i < m_MapY; i++){
            for(int j= 0; j < m_MapX; j++){
                // Select our Tile
                int currentTile = getTileType(i,j);
                if(currentTile > -1 ){
                    // Reverse lookup, given the tile type
                    // and then figuring out how to select it
                    // from the texture atlas.
                    Src.x = (currentTile % m_Cols) * m_TileWidth;
                    Src.y = (currentTile / m_Rows) * m_TileHeight;
                    Src.w = m_TileWidth; 
                    Src.h = m_TileHeight; 
                    // Render our Tile at this location
                    Dest.x = j*m_TileWidth;
                    Dest.y = i*m_TileHeight;
                    Dest.w = m_TileWidth;
                    Dest.h = m_TileHeight;
                    SDL_RenderCopy(ren, m_Texture, &Src, &Dest);
                }
            }
        }
    }

private:
    // Dimensions of our TileMap and individual tiles.
    int m_Rows,m_Cols;  // Used for spiltting up the sprite sheet
    int m_TileWidth,m_TileHeight; // How big each tile is.
    int m_MapX, m_MapY; // size of our tilemap
    // Where our TileMap is rendered
    // An SDL Surface contains pixel data to draw our TileMap
    SDL_Surface *m_TileSpriteSheet;
    SDL_Texture *m_Texture;
    // Stores our tile types
    int* m_Tiles;
};

#endif
